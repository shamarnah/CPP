#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\n" << "checking user input" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]\n" << "user logged in successfully" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]\n" << "disk space is running low" << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]\n" << "failed to save this file" << std::endl;
}

void Harl::complain(std::string level)
{
    /*if (level.empty())
    {
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
        return;
    }*/

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            index = i;
            break;
        }
    }
    switch (index)
    {
        case 0:
            (this->*functions[0])();
        case 1:
            (this->*functions[1])();
        case 2:
            (this->*functions[2])();
        case 3:
            (this->*functions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}