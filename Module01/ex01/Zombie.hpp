#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include<iostream>

class   Zombie{

public:
		Zombie();
		~Zombie();
		
		void        announce();
		void        set_name(std::string);
		static int  total;

private:
		std::string	_name;
};

Zombie*    zombieHorde(int N, std::string name);

#endif
