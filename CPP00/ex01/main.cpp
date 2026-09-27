#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	while (true)
	{
		std::string command;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
