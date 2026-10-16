#ifndef FILEWORK_HPP
#define FILEWORK_HPP

#include <iostream>
#include <string>
#include <fstream>

class fileWork {

    private:
    std::string fileName;
    std::string s1;
    std::string s2;

    public:
    fileWork(std::string fileName, std::string s1, std::string s2);
    void replaceStrings();
};

#endif