#include <iostream>
#include <string>
#include <fstream>

void replace(std::string &line, std::string s1, std::string s2)
{
    size_t pos = 0;
    while (((pos = line.find(s1, pos)) != std::string::npos))
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
}

void handle_files(std::string filename, std::string s1, std::string s2)
{
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cout << "File not found" << std::endl;
        return ;
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cout << "File not created" << std::endl;
        return ;
    }
    std::string buffer_line;
    while (std::getline(infile, buffer_line))
    {
        replace(buffer_line, s1, s2);
        outfile << buffer_line << std::endl;
    }
    infile.close();
    outfile.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "usage: filename s1 s2" << std::endl;
        return 1;
    }
    handle_files(argv[1], argv[2], argv[3]);
    return 0;
}
