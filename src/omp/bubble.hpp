#include "../helpers/file-manager.hpp"

class BubbleOMP
{
public:
    FileManager *m_file_manager;

    BubbleOMP();
    ~BubbleOMP();

    void sort();
    void bubble_sort(int *t_arr, int t_size);
};

BubbleOMP::BubbleOMP()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-bubble-omp.txt");
}

BubbleOMP::~BubbleOMP()
{
    delete m_file_manager;
}

void BubbleOMP::bubble_sort(int *t_arr, int t_size)
{
    int i, tmp, changes;
    int chunk = t_size / 4;
    changes = 1;
    int nr = 0;
    while (changes)
    {
        #pragma omp parallel private(tmp)
        {
            nr++;
            changes = 0;
            #pragma omp for reduction(+ \
                          : changes)
                for (i = 0; i < t_size - 1; i = i + 2)
                {
                    if (t_arr[i] > t_arr[i + 1])
                    {
                        tmp = t_arr[i];
                        t_arr[i] = t_arr[i + 1];
                        t_arr[i + 1] = tmp;
                        ++changes;
                    }
                }
            #pragma omp for reduction(+ \
                          : changes)
                for (i = 1; i < t_size - 1; i = i + 2)
                {
                    if (t_arr[i] > t_arr[i + 1])
                    {
                        tmp = t_arr[i];
                        t_arr[i] = t_arr[i + 1];
                        t_arr[i + 1] = tmp;
                        ++changes;
                    }
                }
        }
    }
}

void BubbleOMP::sort()
{
    std::cout << "Iniciando ordenação - Bubble Sort (OpenMP)" << std::endl;

    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-bubble-omp.txt");

    bubble_sort(m_file_manager->m_arr, m_file_manager->m_vec.size());

    delete m_file_manager;
}