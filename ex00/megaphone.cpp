#include <iostream>

int main (int argc, char **argv)
{
	int i;
	int	j;
	int len;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		len = 0;
		while (argv[i][len])
			len++;
		for (j = 0; j < len; j++)
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] = argv[i][j] - 'a' + 'A';
			std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}
