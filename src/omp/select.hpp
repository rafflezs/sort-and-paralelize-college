#include "../helpers/file-manager.hpp"

class SelectOMP
{
public:
    FileManager *m_file_manager{nullptr};
    typedef struct compare
    {
        int val;
        int index;
    } Compare;

    #pragma omp declare reduction(maximum:Compare:omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)

    SelectOMP();
    ~SelectOMP();

    void sort();
    void swap(int *a, int *b);
    void selection_sort(int *arr, int n);
};

SelectOMP::SelectOMP()
{
    std::cout << "Gerando arquivo" << std::endl;
    m_file_manager = new FileManager("../data/unsort-input.txt", "../data/sorted-select-omp.txt");
}

SelectOMP::~SelectOMP()
{
    delete m_file_manager;
}

void SelectOMP::selection_sort(int *arr, int n)
{
    for (int i = n - 1; i > 0; --i)
    {
        Compare max;
        max.val = arr[i];
        max.index = i;
        #pragma omp parallel for reduction(maximum:max)
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > max.val)
            {
                max.val = arr[j];
                max.index = j;
            }
        }
        
        int tmp = arr[i];
        arr[i] = max.val;
        arr[max.index] = tmp;
    }
}

void SelectOMP::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void SelectOMP::sort()
{

    std::cout << "Iniciando ordenação - Select Sort (OpenMP)" << std::endl;

    selection_sort(m_file_manager->m_arr, m_file_manager->m_vec.size());
}