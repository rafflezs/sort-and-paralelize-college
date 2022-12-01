#include "../helpers/file-manager.hpp"

class SelectSerial
{
public:
    FileManager *m_file_manager{nullptr};

    SelectSerial();
    ~SelectSerial();

    void sort();
    void swap(int *a, int *b);
    void selection_sort(int *arr, int n);
};

SelectSerial::SelectSerial()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-seelct-serial.txt");
}

SelectSerial::~SelectSerial()
{
    delete m_file_manager;
}

void SelectSerial::selection_sort(int *arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void SelectSerial::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void SelectSerial::sort()
{

    std::cout << "Iniciando ordenação - Select Sort" << std::endl;

    m_file_manager->print_array();

    int* arr = m_file_manager->m_arr;

    selection_sort(arr, m_file_manager->m_vec.size());

    m_file_manager->m_arr = arr;

    m_file_manager->print_array();
}