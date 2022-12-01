#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

class UnsortedGenerator
{
public:
    void generate_file(int t_size, int t_min, int t_max, bool is_float)
    {
        std::cout << "Gerando lista de valores randomicos" << std::endl;

        std::ofstream unsorted_input("../data/unsort-input.txt");
        std::srand(std::time(0));

        if (is_float)
        {
            std::random_device rd;
            std::default_random_engine eng(rd());
            std::uniform_real_distribution<float> distr(t_min, t_max);

            for (int i = 0; i < t_size; i++)
            {
                unsorted_input << std::setprecision(2) << t_min + (float)(rand()) / ((float)(RAND_MAX / (t_max - t_min))) << std::endl;
            }
        }
        else
        {
            for (int i = 0; i < t_size; i++)
            {
                unsorted_input << (rand() % t_max) + t_min << std::endl;
            }
        }
    };
};