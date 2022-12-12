#include "../helpers/file-manager.hpp"
#include "mpi.h"

class BubbleMPI
{
public:
    FileManager *m_file_manager;

    BubbleMPI();
    ~BubbleMPI();

    void sort(int argc, char **argv);
    void bubble_sort(int argc, char **argv, int *t_arr, int t_size);
};

BubbleMPI::BubbleMPI()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-bubble-mpi.txt");
}

BubbleMPI::~BubbleMPI()
{
    delete m_file_manager;
}

void BubbleMPI::bubble_sort(int argc, char **argv, int *t_arr, int t_size)
{
    double start, stop;
    start = clock();
    int size, rank;
    int *c = t_arr;
    int aa[t_size], cc[t_size];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Scatter(t_arr, t_size / size, MPI_INT, aa, t_size / size, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

    int n = t_size / size;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (aa[j] > aa[j + 1])
            {
                int temp = aa[j];
                aa[j] = aa[j + 1];
                aa[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cc[i] = aa[i];
    };

    stop = clock();
    if (rank == 0)
        printf("Bubble MPI - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Gather(cc, t_size / size, MPI_INT, c, t_size / size, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}

void BubbleMPI::sort(int argc, char **argv)
{
    std::cout << "Iniciando ordenação - Bubble Sort (OpenMP)" << std::endl;

    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-bubble-mpi.txt");

    bubble_sort(argc, argv, m_file_manager->m_arr, m_file_manager->m_vec.size());
}