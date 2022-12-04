#include "../helpers/file-manager.hpp"

class QuickSerial
{
public:
    FileManager *m_file_manager;

    QuickSerial();
    ~QuickSerial();

    void sort();
    void swap(int *a, int *b);
    int partition(int *arr, int low, int high);
    void quick_sort(int *arr, int low, int high);
};

QuickSerial::QuickSerial()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-quick-serial.txt");
}

QuickSerial::~QuickSerial()
{
    delete m_file_manager;
}

void QuickSerial::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int QuickSerial::partition(int *arr, int low, int high)
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

void QuickSerial::quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Driver Code
void QuickSerial::sort()
{
    std::cout << "Iniciando ordenação - Quick Sort" << std::endl;

    quick_sort(m_file_manager->m_arr, 0, m_file_manager->m_vec.size() - 1);
}