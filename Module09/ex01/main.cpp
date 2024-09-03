#include "RPN.hpp"

int main(int argc, char* argv[])
{
	int i = 0;
	Rpn numberStore;
	int a;
	int b;

	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "Error: Es necesario un argumento." << std::endl;
		return (0);
	}
	while (argv[1][i] == ' ')
		i++;
	if (argv[1][i] == '\0')
	{
		std::cerr << "Error: Es necesario un argumento." << std::endl;
		return (0);
	}
	try
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				numberStore.setRpnOperand(argv[1][i] - '0');
				i++;
			}
			else if (argv[1][i] == '+')
			{
				b = numberStore.getRpnOperand();
				a = numberStore.getRpnOperand();
				numberStore.setRpnOperand(a + b);
				i++;
			}
			else if (argv[1][i] == '-')
			{
				b = numberStore.getRpnOperand();
				a = numberStore.getRpnOperand();
				numberStore.setRpnOperand(a - b);
				i++;
			}
			else if (argv[1][i] == '*')
			{
				b = numberStore.getRpnOperand();
				a = numberStore.getRpnOperand();
				numberStore.setRpnOperand(a * b);
				i++;
			}
			else if (argv[1][i] == '/')
			{
				b = numberStore.getRpnOperand();
				a = numberStore.getRpnOperand();
				numberStore.setRpnOperand(a / b);
				i++;
			}

			else if (argv[1][i] != ' ')
			{
				if (argv[1][i] == '\0')
					break;
				std::cerr << "Error: Probably the argument has a sintax error." << std::endl;
				return (1); 
			}
			else
				i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Excepción estándar capturada.- " << e.what() << std::endl;
		return(1);
	}
	int result = numberStore.getRpnOperand();
	if (numberStore.hasNoOperand() == true)
		std::cout << "Solución: " << result << std::endl;
	else
		std::cout << "Error de sintaxis en el parámetro introducido. " << std::endl;
	return(0);
}
