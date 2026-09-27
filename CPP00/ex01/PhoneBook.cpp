#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nextInd = 0;
	contactCount = 0;
}
void PhoneBook::addContact()
{
	std::string input;
	std::cout << "enter your first name: ";
	std::getline(std::cin, input);
	contacts[nextInd].setFirstName(input);
	std::cout << "enter your last name: ";
	std::getline(std::cin, input);
	contacts[nextInd].setLastName(input);
	std::cout << "enter your nickname: ";
	std::getline(std::cin, input);
	contacts[nextInd].setNickname(input);
	std::cout << "enter your phone number: ";
	std::getline(std::cin, input);
	contacts[nextInd].setPhoneNumber(input);
	std::cout << "enter your darkest secret: ";
	std::getline(std::cin, input);
	contacts[nextInd].setDarkestSecret(input);
	nextInd++;
	if (nextInd > 7)
		nextInd = 0;
	if (contactCount < 8)
		contactCount++;
}
std::string PhoneBook::formatLongContact(std::string contact)
{
    if (contact.length() > 10)
        return contact.substr(0, 9) + ".";
    return contact;
}
void PhoneBook::searchContact()
{
    std::cout << std::setw(10) << "index"
        << "|" << std::setw(10) << "first name"
        << "|" << std::setw(10) << "last name"
        << "|" << std::setw(10) << "nickname"
        << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i 
            << "|" << std::setw(10) << formatLongContact(contacts[i].getFirstName())
            << "|" << std::setw(10) << formatLongContact(contacts[i].getLastName())
            << "|" << std::setw(10) << formatLongContact(contacts[i].getNickname())
            << std::endl;
    }

    std::cout << "Enter the number of the contact you want to see: " << std::endl;
	std::string input;
	int index;
	std::getline(std::cin, input);
	std::stringstream ss(input);
	if (!(ss >> index) || !(ss.eof()))
	{
    	std::cout << "Invalid input" << std::endl;
		return;
	}
	if (index < 0 || index >= contactCount)
	{
    	std::cout << "Invalid input" << std::endl;
		return;
	}
	else
	{
    	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
}
