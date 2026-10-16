#include <iostream>

int main()
{
    std::string x = "HI THIS IS BRAIN";
    std::string *ptr = &x;
    std::string &ref = x;

    std::cout << "The memory address of the string variable: " << &x << std::endl;
    std::cout << "The memory address held by ptr: " <<  ptr << std::endl;
    std::cout << "The memory address held by ref: " << &ref << std::endl;
    std::cout << "The value of the string variable: " << x << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *ptr << std::endl;
    std::cout << "The value pointed to by stringREF: " << ref << std::endl;

    return 0;
}