#include "merge.hpp"

MergeSerial::MergeSerial(FileManager* in_file)
{

}

void MergeSerial::merge(int const left, int const mid, int const right)
{
    auto const sub_left = mid - left + 1;
    auto const sub_right = right - mid;

    auto *leftArray = new int[sub_left],
         *rightArray = new int[sub_right];

    for (auto i = 0; i < sub_left; i++)
        leftArray[i] = m_arr[left + i];
    for (auto j = 0; j < sub_right; j++)
        rightArray[j] = m_arr[mid + 1 + j];

    auto indexOfsub_left = 0,
        indexOfsub_right = 0;
    int indexOfMergedArray = left;

    while (indexOfsub_left < sub_left && indexOfsub_right < sub_right)
    {
        if (leftArray[indexOfsub_left] <= rightArray[indexOfsub_right])
        {
            m_arr[indexOfMergedArray] = leftArray[indexOfsub_left];
            indexOfsub_left++;
        }
        else
        {
            m_arr[indexOfMergedArray] = rightArray[indexOfsub_right];
            indexOfsub_right++;
        }
        indexOfMergedArray++;
    }

    while (indexOfsub_left < sub_left)
    {
        m_arr[indexOfMergedArray] = leftArray[indexOfsub_left];
        indexOfsub_left++;
        indexOfMergedArray++;
    }

    while (indexOfsub_right < sub_right)
    {
        m_arr[indexOfMergedArray] = rightArray[indexOfsub_right];
        indexOfsub_right++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// void MergeSerial::merge_sort(int const begin, int const end)
// {
//     if (begin >= end)
//         return; // Returns recursively

//     auto mid = begin + (end - begin) / 2;
//     merge_sort(m_arr, begin, mid);
//     merge_sort(m_arr, mid + 1, end);
//     merge(m_arr, begin, mid, end);
// }


void MergeSerial::print()
{
    for (auto i = 0; i < sizeof(m_arr); i++)
        std::cout << m_arr[i] << " ";
}

