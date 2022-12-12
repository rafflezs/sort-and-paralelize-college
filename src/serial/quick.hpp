#include "../helpers/file-manager.hpp"

class QuickSerial
{
public:
    FileManager *m_file_manager;
    void sort();
    void swap(int *a, int *b);
    int partition(int *t_arr, int low, int high);
    void quick_sort(int *t_arr, int low, int high);
};

void QuickSerial::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int QuickSerial::partition(int *t_arr, int low, int high)
{
    int pivot = t_arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (t_arr[j] < pivot)
        {
            i++;
            swap(&t_arr[i], &t_arr[j]);
        }
    }
    swap(&t_arr[i + 1], &t_arr[high]);
    return (i + 1);
}

void QuickSerial::quick_sort(int *t_arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(t_arr, low, high);

        quick_sort(t_arr, low, pi - 1);
        quick_sort(t_arr, pi + 1, high);
    }
}

// Driver Code
void QuickSerial::sort()
{

    std::cout << "Iniciando ordenação - Select Sort" << std::endl;

    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-quick-serial.txt");

    double start, stop;
    start = clock();
    quick_sort(m_file_manager->m_arr, 0, m_file_manager->m_vec.size() - 1);
    stop = clock();
    printf("Quick Serial - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    delete m_file_manager;
}