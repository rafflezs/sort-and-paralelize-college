#include "../helpers/file-manager.hpp"

class BubbleSerial
{
public:
    FileManager *m_file_manager;

    BubbleSerial();
    ~BubbleSerial();

    void sort();
    void bubble_sort(int *t_arr, int t_size);
};

BubbleSerial::BubbleSerial()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-bubble-serial.txt");
}

BubbleSerial::~BubbleSerial()
{
    delete m_file_manager;
}

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
    std::cout << "Iniciando ordenação - Bubble Sort" << std::endl;

    bubble_sort(m_file_manager->m_arr, m_file_manager->m_vec.size());
}