#ifndef _FILE_MANAGER_HPP
#define _FILE_MANAGER_HPP

#include<fstream>

class FileManager
{
private:
    std::ifstream in_file{};
public:
    FileManager(std::string file_name);
    ~FileManager();

    void save_output(std::string file_name);
};

FileManager::FileManager(std::string file_name)
{
    in_file.open(file_name);
}

FileManager::~FileManager()
{
}

void FileManager::save_output(std::string file_name)
{
    std::ofstream save_file{};
}

#endif // !_FILE_MANAGER_HPP