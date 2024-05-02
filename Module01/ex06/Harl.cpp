#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void ){
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese";
	std::cout << "-triple-pickle-special-ketchup burger.\nI really do!\n";
	std::cout << std::endl;
}

void Harl::info( void ){
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn't put enough bacon in my burger! If you did, I";
	std::cout << " wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning( void ){
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years whereas you started working ";
	std::cout << "here since last month.\n" << std::endl;
}

void Harl::error( void ){
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
	std::cout << std::endl;
}

void Harl::complain( std::string level ){
	int			i;
	std::string	strLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < 4; i++)
	{
		if (strLevel[i] == level)
			break;
	}
	if (strLevel[i] != level)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	switch(i)
	{
		case 0:
			this->Harl::debug();
		case 1:
			this->Harl::info();
		case 2:
			this->Harl::warning();
		case 3:
			this->Harl::error();
	}
}
