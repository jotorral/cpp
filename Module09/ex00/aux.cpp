#include "aux.hpp"
#include <stdlib.h>

std::string    checkLineFormat (std::string line)
{
	size_t pipePos = line.find(" | ");
	if (pipePos != 10)
		return ("Error: bad input line format ==> " + line);
	std::string beforePipe = line.substr(0, pipePos); // string with date
	std::string afterPipe = line.substr(pipePos + 3); // string with value

	//	***** Date format *****
	if (beforePipe.size() != 10 || beforePipe[4] != '-' || beforePipe [7] != '-')				// '-' format
		return ("Error: bad input date format ==> " + beforePipe);
	if (line.at(0) != '2' || line.at(1) != '0' || line.at(2) > '2' || line.at(2) < '0' || line.at(3) > '9' || line.at(3) < '0')	// Year format
		return ("Error: bad input date year ==> " + beforePipe);
//	int year = atoi((line.substr(0, 4)).c_str());
//		std::cout << "Year: " << year << std::endl;
	if (atoi((line.substr(0, 4)).c_str()) < 2009 || atoi((line.substr(0, 4)).c_str()) > 2024)	// Year values
		return ("Error: bad input date. Year out of range ==> " + beforePipe);
	if (line.at(5) > '1' || line.at(5) < '0' || line.at(6) > '9' || line.at(6) < '0')			// Month format
		return ("Error: bad input date month ==> " + beforePipe);
	if (atoi((line.substr(5, 6)).c_str()) < 1 || atoi((line.substr(5, 6)).c_str()) > 12)		// Month values
		return ("Error: bad input date. Month out of range ==> " + beforePipe);
	if (line.at(8) > '3' || line.at(8) < '0' || line.at(9) > '9' || line.at(9) < '0')			// Day format
		return ("Error: bad input date day ==> " + beforePipe);
	if (atoi((line.substr(8, 9)).c_str()) < 1 || atoi((line.substr(8, 9)).c_str()) > 31)		// Day values
		return ("Error: bad input date. Day out of range ==> " + beforePipe);
	
	// ***** Value format *****
	if (afterPipe.size() < 1 || afterPipe.size() > 10)					// Value has between 1 and 10 characters
		return ("Error: bad input line format ==> " + line);
	if (afterPipe.at(0) == '-')											// Value is not negative
		return ("Error: not a positive number ==> " + afterPipe);
	int dot = 0;
	for (unsigned int i = 0; i < afterPipe.size(); i++)					// Value has numbers ('0' - '9') and not more than one '.'
	{
		if (afterPipe.at(i) == '.')
			dot++;
		if (dot > 1)
			return ("Error: bad input value1 ==> " + afterPipe);
		if (afterPipe.at(i) != '.' && (afterPipe.at(i) < '0' || afterPipe.at(i) > '9'))
		{
//			std::cout << "Character which fails: " << afterPipe.at(i) << std::endl;
			return ("Error: bad input value2 ==> " + afterPipe);
		}
		char* end;
		if (std::strtod(afterPipe.c_str(), &end) < 0 || std::strtod(afterPipe.c_str(), &end) > 1000)	// Value negative or > 1000
			return ("Error: value too high ==> " + afterPipe);
	}
	return("");
}
