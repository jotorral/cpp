#include "utility.hpp"

void	newFile (std::string _str, char **argv)
{
	std::ofstream	_outFile;
	std::ifstream	_infile((std::string(argv[1]) + ".replace").c_str());
	std::string		oldString = argv[2];
	std::string		newString = argv[3];

	if (_infile.is_open())
	{
		std::cerr << "Error: File <<" << argv[1] << ".replace>> already exist. Change the name of this existing file or remove it." << std::endl;
		return;
	}
	_outFile.open((std::string(argv[1]) + ".replace").c_str()); //c_str facilita un "const char *" a partir de un "std:string" y garantiza que la cadena termine en \0.
	if(_outFile.fail()) {
		std::cerr << "Error: File \"" << (std::string(argv[1]) + ".replace").c_str() << "\" opening error" << std::endl;
		return;
	}
	else
	{
		size_t pos = 0;
		while ((pos = _str.find(oldString, pos)) != std::string::npos) // cuando no hay coincidencia posterior, pos = npos
		{
			try{
					_str.erase(pos, oldString.length());
					_str.insert(pos, newString);
					pos += newString.length();
				}
			catch (const std::bad_alloc& e) {
					std::cerr << "Error de memoria al modificar el contenido." << std::endl;
				}
		}
		_outFile << _str; // Escribir el contenido modificado del string al archivo
		if (_outFile.fail()) {
			std::cerr << "Error writing to file" << (std::string(argv[1]) + ".replace").c_str() << ".";
			return;
		}
	}
	_infile.close();
	_outFile.close();
	return;
}

int main(int argc, char **argv)
{
	std::ifstream	_file;
	std::string		_str = "\0";

	if (argc != 4)
		return (std::cerr << "Error: It is necessary to add 3 arguments to the program " << argv[0] << std::endl, 1);
	if (!_file)
		return (std::cerr << "Error: File << " << argv[1] << " >> does not exist or cannot be opened." << std::endl, 1);
	_file.open(argv[1]);
	if(_file.fail())
		return (std::cerr << "Error: File << " << argv[1] << " >> opening error." << std::endl, 1);
	if (_file.peek() == std::ifstream::traits_type::eof())
		return (std::cerr << "Error: The file << " << argv[1] << " >> is empty or inappropriate.\n", 1);
	_str = std::string((std::istreambuf_iterator<char>(_file)), std::istreambuf_iterator<char>()); // _str = fichero desde el principio hasta el final
	_file.close();
	newFile (_str, argv);
//	system("leaks sed");
	return(0);
}
