#include "../helpers/file-manager.hpp"

class SelectSerial
{
public:
    FileManager *m_file_manager;
    void sort();
    void swap(int *xp, int *yp);
    void selection_sort(std::vector<int>* arr, int n);
};

void SelectSerial::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectSerial::selection_sort(std::vector<int>* arr, int n)
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

void SelectSerial::sort()
{
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-seelct-serial.txt");
    auto arr_size = m_file_manager->m_to_sort.size;
    selection_sort(*(m_file_manager->m_to_sort.m_arr), arr_size);
    delete m_file_manager;
}