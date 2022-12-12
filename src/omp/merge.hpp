#include "../helpers/file-manager.hpp"

class MergeOMP
{
public:
    FileManager *m_file_manager;

    MergeOMP();
    ~MergeOMP();

    void sort();
    void merge(int *t_arr, int n, int *tmp);
    void merge_sort(int *t_arr, int n, int *tmp);
};

MergeOMP::MergeOMP()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-merge-omp.txt");
}

MergeOMP::~MergeOMP()
{
    delete m_file_manager;
}

void MergeOMP::merge(int *t_arr, int n, int *tmp)
{
    int i = 0;
    int j = n / 2;
    int ti = 0;
    // i will iterate till first  half anf J will iterate for 2nd half of array
    while (i < n / 2 && j < n)
    {
        if (t_arr[i] < t_arr[j])
        {
            tmp[ti] = t_arr[i];
            ti++;
            i++;
        }
        else
        {
            tmp[ti] = t_arr[j];
            ti++;
            j++;
        }
    }
    while (i < n / 2)
    { /* finish up lower half */
        tmp[ti] = t_arr[i];
        ti++;
        i++;
    }
    while (j < n)
    { /* finish up upper half */
        tmp[ti] = t_arr[j];
        ti++;
        j++;
    }
    // Copy sorted array tmp back to  t_arr (Original array)
    memcpy(t_arr, tmp, n * sizeof(int));
}

void MergeOMP::merge_sort(int *t_arr, int n, int *tmp)
{
    if (n < 2)
        return;

#pragma omp task firstprivate(t_arr, n, tmp)
    merge_sort(t_arr, n / 2, tmp);

#pragma omp task firstprivate(t_arr, n, tmp)
    merge_sort(t_arr + (n / 2), n - (n / 2), tmp);

// Wait for both paralel tasks to complete execution
#pragma omp taskwait

    /* merge sorted halves into sorted list */
    merge(t_arr, n, tmp);
}

void MergeOMP::sort()
{
    std::cout << "Iniciando ordenação - Merge Sort (OpenMP)" << std::endl;

    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-merge-omp.txt");

    double start, stop;
    start = clock();

    int tmp[m_file_manager->m_vec.size()];
#pragma omp parallel
    {
#pragma omp single
        merge_sort(m_file_manager->m_arr, m_file_manager->m_vec.size(), tmp);
    }

    stop = clock();
    printf("Merge OpenMP - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);
}