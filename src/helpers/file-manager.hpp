#ifndef _FILE_MANAGER_HPP
#define _FILE_MANAGER_HPP

#include <fstream>
#include "sort-struct.hpp"

class FileManager
{
public:
    // Atributos
    std::string m_output_name{""};
    std::ifstream in_file{};
    SortStruct m_to_sort{};

    // Metodos
    FileManager(std::string t_input_name, std::string t_output_name);
    ~FileManager();
};

FileManager::FileManager(std::string t_input_name, std::string t_output_name)
{
    this->m_output_name = t_output_name;
    
    in_file.open(t_input_name);

    std::string line;
    while (getline(in_file, line))
    {
        m_to_sort.m_arr.push_back(std::stoi(line));
        m_to_sort.size++;
    }
}

FileManager::~FileManager()
{
    std::ofstream output_file(m_output_name);

    for (auto i = m_to_sort.m_arr.begin(); i != m_to_sort.m_arr.end(); i++)
    {
        output_file << *(i) << "\n";
    }
}

#endif // !_FILE_MANAGER_HPP