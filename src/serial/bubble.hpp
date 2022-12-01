// #include "../helpers/file-manager.hpp"

// class BubbleSerial
// {
// public:
//     FileManager* m_file_manager;
//     void sort();
//     void bubble_sort(std::vector<int> *t_arr, int t_size);
// };

// void BubbleSerial::bubble_sort(std::vector<int> *t_arr, int t_size)
// {
//     int i, j;
//     for (i = 0; i < t_size - 1; i++)
//         for (j = 0; j < t_size - i - 1; j++)
//             if (t_arr[j] > t_arr[j + 1])
//                 std::swap(t_arr[j], t_arr[j + 1]);
// }

// void BubbleSerial::sort()
// {
//     m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-bubble-serial.txt");
//     bubble_sort(m_file_manager->m_to_sort->m_arr, m_file_manager->m_to_sort->m_arr->size());
//     delete m_file_manager;
// }