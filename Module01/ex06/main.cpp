#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl    obj;

	if (argc != 2)
	{
		std::cerr << "You must type 1 parameter in." << std::endl;
		return (0);
	}
	obj.complain( argv[1] );
	return(0);
}
