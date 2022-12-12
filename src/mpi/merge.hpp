#include "../helpers/file-manager.hpp"
#include <mpi.h>

class MergeMPI
{
public:
    FileManager *m_file_manager;

    MergeMPI();
    ~MergeMPI();

    void sort(int argc, char **argv);
    int *merge(int *First, int Fsize, int *Second, int Ssize);
    void merge_sort(int *Arr, int start, int end);
};

MergeMPI::MergeMPI()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-merge-mpi.txt");
}

MergeMPI::~MergeMPI()
{
    delete m_file_manager;
}

int *MergeMPI::merge(int *First, int Fsize, int *Second, int Ssize)
{
    int fi = 0, si = 0, mi = 0, i;
    int *merged;
    int Msize = Fsize + Ssize;

    merged = (int *)malloc(Msize * sizeof(int));
    while ((fi < Fsize) && (si < Ssize))
    {
        if (First[fi] <= Second[si])
        {
            merged[mi] = First[fi];
            mi++;
            fi++;
        }
        else
        {
            merged[mi] = Second[si];
            mi++;
            si++;
        }
    }

    if (fi >= Fsize)
        for (i = mi; i < Msize; i++, si++)
            merged[i] = Second[si];
    else if (si >= Ssize)
        for (i = mi; i < Msize; i++, fi++)
            merged[i] = First[fi];

    for (i = 0; i < Fsize; i++)
        First[i] = merged[i];
    for (i = 0; i < Ssize; i++)
        Second[i] = merged[Fsize + i];

    return merged;
}

void MergeMPI::merge_sort(int *Arr, int start, int end)
{
    int *sortedArr;
    int mid = (start + end) / 2;
    int leftCount = mid - start + 1;
    int rightCount = end - mid;

    /* If the range consists of a single element, it's already sorted */
    if (end == start)
    {
        return;
    }
    else
    {
        /* sort the left half */
        merge_sort(Arr, start, mid);
        /* sort the right half */
        merge_sort(Arr, mid + 1, end);
        /* merge the two halves */
        sortedArr = merge(Arr + start, leftCount, Arr + mid + 1, rightCount);
    }
}

void MergeMPI::sort(int argc, char **argv)
{
    std::cout << "Iniciando ordenação - Merge Sort" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-merge-mpi.txt");

    int *data = m_file_manager->m_arr;
    int *local_data;
    int *otherArr;
    int q, n = m_file_manager->m_vec.size();
    int my_rank, comm_sz;
    int local_n = 0;
    int i;
    int step;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

    if (my_rank == 0)
    {
        int r;
        local_n = n / comm_sz;
        r = n % comm_sz;
        int size = n + local_n - r;

        if (r != 0)
        {
            for (i = n; i < size; i++)
                data[i] = 0;
            local_n = local_n + 1;
        }

        // Print unsorted data
        MPI_Bcast(&local_n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        local_data = (int *)malloc(local_n * sizeof(int));
        MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);
        merge_sort(local_data, 0, local_n - 1);
    }
    else
    {
        MPI_Bcast(&local_n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        local_data = (int *)malloc(local_n * sizeof(int));
        MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);
        merge_sort(local_data, 0, local_n - 1);
    }

    // Print sorted data per processor
    step = 1;
    while (step < comm_sz)
    {
        if (my_rank % (2 * step) == 0)
        {
            if (my_rank + step < comm_sz)
            {
                MPI_Recv(&q, 1, MPI_INT, my_rank + step, 0, MPI_COMM_WORLD, &status);
                otherArr = (int *)malloc(q * sizeof(int));
                MPI_Recv(otherArr, q, MPI_INT, my_rank + step, 0, MPI_COMM_WORLD, &status);
                local_data = merge(local_data, local_n, otherArr, q);
                local_n = local_n + q;
            }
        }
        else
        {
            int dest = my_rank - step;
            MPI_Send(&local_n, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
            MPI_Send(local_data, local_n, MPI_INT, dest, 0, MPI_COMM_WORLD);
            break;
        }
        step = step * 2;
    }

    MPI_Finalize();
}