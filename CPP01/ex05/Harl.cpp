#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "checking user input" << std::endl;
}

void Harl::info(void) {
    std::cout << "user logged in successfully" << std::endl;
}

void Harl::warning(void) {
    std::cout << "disk space is running low" << std::endl;
}

void Harl::error(void) {
    std::cout << "failed to save this file" << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[4])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
    };
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i]) 
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "Invalid level." << std::endl;
}