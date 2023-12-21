/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotorral <jotorral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:20:53 by aperez-b          #+#    #+#             */
/*   Updated: 2023/12/20 17:32:45 by jotorral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
	Account::_nbAccounts--;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp(void)
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << \
		";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits() << \
		";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits << \
		";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << \
		";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << \
	this->_amount << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->checkAmount() - withdrawal << \
		";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return (true);
}	
    
/*    
    
    #include "account.hpp"
    
    static void	_displayTimestamp( void ){}
    
    static int	getNbAccounts( void ){}
	static int	getTotalAmount( void ){}
	static int	getNbDeposits( void ){}
	static int	getNbWithdrawals( void ){}
	static void	displayAccountsInfos( void ){} // está en class Account y avisa al compilar tests.cpp

	Account( int initial_deposit ){} // está en class Account y avisa al compilar tests.cpp
	~Account( void ){} // está en class Account y avisa al compilar tests.cpp

	void	makeDeposit( int deposit ){} // está en class Account y avisa al compilar tests.cpp
	bool	makeWithdrawal( int withdrawal ){} // está en class Account y avisa al compilar tests.cpp
	int		checkAmount( void ) const{}
	void	displayStatus( void ) const{} // está en class Account y avisa al compilar tests.cpp
*/
	/*
jotorral@c3r3s2 ex02 % c++ tests.cpp -Wall -Wextra -Werror -std=c++98 -o tests
Undefined symbols for architecture x86_64:
  "Account::makeDeposit(int)", referenced from:
      _main in tests-60af61.o
  "Account::makeWithdrawal(int)", referenced from:
      _main in tests-60af61.o
  "Account::displayAccountsInfos()", referenced from:
      _main in tests-60af61.o
  "Account::Account(int)", referenced from:
      void std::__1::allocator<Account>::construct<int>(Account*, int const&) in tests-60af61.o
  "Account::~Account()", referenced from:
      std::__1::allocator<Account>::destroy(Account*) in tests-60af61.o
  "Account::displayStatus() const", referenced from:
      _main in tests-60af61.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
*/