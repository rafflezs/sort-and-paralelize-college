#include "../helpers/file-manager.hpp"
#include <omp.h>

class QuickOMP
{
public:
    FileManager *m_file_manager;

    QuickOMP();
    ~QuickOMP();

    void sort();
    void swap(int *a, int *b);
    int partition(int *arr, int low, int high);
    void quick_sort(int *arr, int low, int high);
};

QuickOMP::QuickOMP()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-quick-omp.txt");
}

QuickOMP::~QuickOMP()
{
    delete m_file_manager;
}

void QuickOMP::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int QuickOMP::partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickOMP::quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
#pragma omp task firstprivate(arr, low, pi)
        {
            quick_sort(arr, low, pi - 1);
        }
        {
            quick_sort(arr, pi + 1, high);
        }
    }
}

// Driver Code
void QuickOMP::sort()
{

    std::cout << "Iniciando ordenação - Quick Sort (OpenMP)" << std::endl;

    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-quick-omp.txt");

    double start, stop;
    start = clock();

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nthrds = omp_get_num_threads();
#pragma omp single nowait
        {
            quick_sort(m_file_manager->m_arr, 0, m_file_manager->m_vec.size() - 1);
        }
    }

    stop = clock();
    printf("Quick OpenMP - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);
}