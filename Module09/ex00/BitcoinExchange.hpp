#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <stdlib.h>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string>	quotations;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(char*);
		BitcoinExchange (const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void		setQuotations(std::ifstream& bitcoinPriceFile);
		std::string getQuotation(const std::string& date);
};
