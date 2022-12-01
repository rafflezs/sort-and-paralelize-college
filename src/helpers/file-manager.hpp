#ifndef _FILE_MANAGER_HPP
#define _FILE_MANAGER_HPP

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

class FileManager
{
public:
    // Atributos
    std::string m_output_name{""};
    std::ifstream in_file{};
    std::vector<int> m_vec{};
    int *m_arr{};

    // Metodos
    FileManager(std::string t_input_name, std::string t_output_name);
    ~FileManager();

    void vector_to_array();

    void print_vector();
    void print_array();
};

FileManager::FileManager(std::string t_input_name, std::string t_output_name)
{
    this->m_output_name = t_output_name;

    in_file.open(t_input_name);

    std::string line;
    while (getline(in_file, line))
    {
        m_vec.push_back(std::stoi(line));
    }

    vector_to_array();
}

FileManager::~FileManager()
{
    std::ofstream output_file(m_output_name);

    for (auto i = 0; i < m_vec.size(); i++)
    {
        output_file << m_arr[i] << "\n";
    }
}

void FileManager::vector_to_array()
{

    m_arr = (int*) malloc(sizeof(int) * m_vec.size());

    for (auto i = 0; i < m_vec.size(); i++)
    {
        m_arr[i] = m_vec[i];
    }
}

void FileManager::print_array()
{
    std::cout << "Imprimindo vetor" << std::endl;

    for (int i = 0; i < m_vec.size(); i++)
    {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

void FileManager::print_vector()
{
    std::cout << "Imprimindo vetor" << std::endl;

    for (auto i : m_vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

#endif // !_FILE_MANAGER_HPP