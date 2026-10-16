#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		void setType(std::string type);
		const std::string& getType();
		// & → return a reference, so we don't make a copy of the string.
		// const → the caller cannot modify the string through the returned reference.
};

#endif