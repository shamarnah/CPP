#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

class PhoneBook
{
	private:
		Contact contacts[8];
		int nextInd;
		int contactCount;

	public:
		PhoneBook();
		void addContact();
		void searchContact();
		std::string formatLongContact(std::string contact);
};

#endif