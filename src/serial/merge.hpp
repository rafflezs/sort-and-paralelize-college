#include "../helpers/file-manager.hpp"

class MergeSerial
{
public:
    FileManager *m_file_manager;
    void sort();
    void merge(int *array, int const left, int const mid, int const right);
    void merge_sort(int *array, int const begin, int const end);
};

void MergeSerial::merge(int *array, int const left, int const mid, int const right)
{
    auto const sub_arr_left = mid - left + 1;
    auto const sub_arr_right = right - mid;

    auto leftArray = new int[sub_arr_left],
         rightArray = new int[sub_arr_right];

    for (auto i = 0; i < sub_arr_left; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < sub_arr_right; j++)
        rightArray[j] = array[mid + 1 + j];

    auto index_fsub_arr_left = 0, index_sub_arr_right = 0;
    int index_merged = left;
    while (index_fsub_arr_left < sub_arr_left && index_sub_arr_right < sub_arr_right)
    {
        if (leftArray[index_fsub_arr_left] <= rightArray[index_sub_arr_right])
        {
            array[index_merged] = leftArray[index_fsub_arr_left];
            index_fsub_arr_left++;
        }
        else
        {
            array[index_merged] = rightArray[index_sub_arr_right];
            index_sub_arr_right++;
        }
        index_merged++;
    }

    while (index_fsub_arr_left < sub_arr_left)
    {
        array[index_merged] = leftArray[index_fsub_arr_left];
        index_fsub_arr_left++;
        index_merged++;
    }

    while (index_sub_arr_right < sub_arr_right)
    {
        array[index_merged] = rightArray[index_sub_arr_right];
        index_sub_arr_right++;
        index_merged++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void MergeSerial::merge_sort(int *array, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void MergeSerial::sort()
{

    std::cout << "Iniciando ordenação - Merge Sort" << std::endl;

    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-merge-serial.txt");

    double start, stop;
    start = clock();
    merge_sort(m_file_manager->m_arr, 0, m_file_manager->m_vec.size() - 1);
    stop = clock();
    printf("Merge Serial - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    delete m_file_manager;

}