#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Debes introducir 1 parámetro" << std::endl;
        return (1);
    }
    if (ScalarConverter::detectType(argv[1]) == 0)
    {
        std::cout << "Parámetro incorrecto !!" << std::endl;
        return (1);
    }

    return (0);
}
