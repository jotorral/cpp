#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default construction performed." << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default destruction performed." << std::endl;
}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &other) : quotations(other.quotations)
{
	std::cout << "Copy construction performed." << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->quotations = other.quotations;
	}
	return(*this);
}

void    BitcoinExchange::setQuotations(std::ifstream &bitcoinPriceFile)
{
	std::string line;
	std::getline(bitcoinPriceFile, line); // Skips first line (header)
	while (std::getline(bitcoinPriceFile, line))
	{
//		std::cout << line << '\n'; // Shows every line of the file
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos)
		{
			std::string beforeComma = line.substr(0, commaPos);
			std::string afterComma = line.substr(commaPos + 1);
			quotations[beforeComma] = afterComma;
//			std::cout << "Antes de la coma: " << beforeComma << std::endl;
//	        std::cout << "Después de la coma: " << afterComma << std::endl;
		}
		else
		{
			std::cout << "No se encontró ninguna coma en la cadena: " << line << std::endl;
		}
	}
}

std::string BitcoinExchange::getQuotation(const std::string& date)
{
	if (quotations.empty())
	{
		return "No quotation available";
	}

	// Gets the iterator of the parameter received date. If date is not found, returns the next date.
	std::map<std::string, std::string>::const_iterator iter = quotations.lower_bound(date);

	// If date is too early
	if (iter == quotations.begin() && date < iter->first)
		return ("No quotation available");

	// If the date is found, return the corresponding quotation
	if (/*iter != quotations.end() && */iter->first != date)
	{
		if (iter != quotations.begin())
			--iter;
		else
			return ("No quotation available");;
	}

	// If we found a valid previous date, return its quotation
	if (iter != quotations.end()) {
		return iter->second;
	}

	// If no quotation is found, return an empty string or an appropriate error message
	return ("No quotation available");
}
