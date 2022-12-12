#include "../helpers/file-manager.hpp"

class BubbleSerial
{
public:
    FileManager *m_file_manager;
    void sort();
    void bubble_sort(int *t_arr, int t_size);
};

void BubbleSerial::bubble_sort(int *t_arr, int t_size)
{
    int i, j;
    for (i = 0; i < t_size - 1; i++)
        for (j = 0; j < t_size - i - 1; j++)
            if (t_arr[j] > t_arr[j + 1])
                std::swap(t_arr[j], t_arr[j + 1]);
}

void BubbleSerial::sort()
{
    std::cout << "Iniciando ordenação - Select Sort" << std::endl;

    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-bubble-serial.txt");

    double start, stop;
    start = clock();
    bubble_sort(m_file_manager->m_arr, m_file_manager->m_vec.size());
    stop = clock();
    printf("Bubble Serial - Tempo gasto: %f\n\n", (stop - start) / CLOCKS_PER_SEC);

    delete m_file_manager;
}