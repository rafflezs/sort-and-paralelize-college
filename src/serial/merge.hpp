#include "../helpers/file-manager.hpp"
#include <iostream>

class MergeSerial
{
private:
    int *m_arr;
    std::string m_arquivo{"merge-serial.txt"};
public:

    MergeSerial(FileManager* in_file);

    int *get_arr();
    void *set_arr();

    std::string to_file();

    void merge(int const left, int const mid, int const right);
    void merge_sort(int const begin, int const end);
    void print();
};
