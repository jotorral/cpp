#include "BitcoinExchange.hpp"
#include "aux.hpp"


int main(int argc, char const *argv[])
{
	std::ifstream bitcoinPriceFile("data.csv"); // Opens file in read mode.
	if (!bitcoinPriceFile)
	{
		std::cerr << "No se pudo abrir el fichero data.csv para lectura.\n";
		return 1;
	}
	BitcoinExchange b;
	b.setQuotations(bitcoinPriceFile); // Puts database of the file in one container.
	bitcoinPriceFile.close(); // Closes the file.

	if (argc != 2)
	{
		std::cout << "Error: You must type in a file name after the program name." << std::endl;
		return (0);
	}
	std::ifstream amountOfBitcoinsFile(argv[1]); // Opens file in read mode.
	if (!amountOfBitcoinsFile)
	{
		std::cerr << "No se pudo abrir el fichero de nombre " << argv[1] << " para lectura.\n";
		return 1;
	}
	std::string line;
	std::getline(amountOfBitcoinsFile, line);
	if (line != "date | value")
	{
		std::cout << "File is empty, or doesn't have the right header: 'date | value' " << line << std::endl;
		return (0);
	}
	while (std::getline(amountOfBitcoinsFile, line))
    {
//		std::cout << line << '\n'; // Shows every line of the file
		std::string lineError = checkLineFormat(line);
		if (lineError != "\0")
			std::cerr << lineError << std::endl;
		else
		{
			size_t pipePos = line.find(" | ");
			char*	end1;
			char*	end2;

			std::string beforePipe = line.substr(0, pipePos);
			std::string afterPipe = line.substr(pipePos + 3);
			std::string quote = b.getQuotation(beforePipe);
			if (quote == "No quotation available")
				std::cout << "Error: No quotation available for: " << beforePipe << std::endl;
			else
			{
				float bitcoinsValue = std::strtod(quote.c_str(), &end1) * std::strtod(afterPipe.c_str(), &end2);
				std::cout << beforePipe << " => " << afterPipe << " * " << quote << " = " << bitcoinsValue << std::endl;
			}
		}
	}
	return (0);
}
