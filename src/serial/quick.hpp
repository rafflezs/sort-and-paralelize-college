// #include "../helpers/file-manager.hpp"

// class QuickSerial
// {
// public:
//     FileManager *m_file_manager;
//     void sort();
//     void swap(int *a, int *b);
//     int partition(std::vector<int> arr, int low, int high);
//     void quick_sort(std::vector<int> arr, int low, int high);
// };

// void QuickSerial::swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// int QuickSerial::partition(std::vector<int> arr, int low, int high)
// {
//     int pivot = arr[high];
//     int i = (low - 1);

//     for (int j = low; j <= high - 1; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }

// void QuickSerial::quick_sort(std::vector<int> arr, int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);

//         quick_sort(arr, low, pi - 1);
//         quick_sort(arr, pi + 1, high);
//     }
// }

// // Driver Code
// void QuickSerial::sort()
// {
//     m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-quick-serial.txt");
//     auto arr_size = m_file_manager->m_to_sort.size;
//     quick_sort(m_file_manager->m_to_sort.m_arr, 0, arr_size - 1);
//     delete m_file_manager;
// }