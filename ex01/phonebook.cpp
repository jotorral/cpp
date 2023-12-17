#include "book.hpp"

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

Contact::Contact(void){return;}

Contact::~Contact(void){return;}

PhoneBook::PhoneBook(void){return;}

PhoneBook::~PhoneBook(void){return;}

std::string	Contact::get_first_name(void)
{
	return _first_name;
}

void		Contact::save_first_name(std::string)
{
	std::cout << "First Name: ";
	std::getline(std::cin, _first_name, '\n');
}
std::string	Contact::get_last_name(void)
{
	return _last_name;
}

void		Contact::save_last_name(std::string)
{
	std::cout << "Last Name: ";
	std::getline(std::cin, _first_name, '\n');
}	
std::string	Contact::get_nickname(void)
{
	return _nickname;
}
void		Contact::save_nickname(std::string)
{
	std::cout << "Nickname: ";
	std::getline(std::cin, _nickname, '\n');
}
std::string	Contact::get_phone_number(void)
{
	return _phone_number;
}
void		Contact::save_phone_number(std::string)
{
	std::cout << "Phone number: ";
	std::getline(std::cin, _phone_number, '\n');
}	
std::string	Contact::get_darkest_secret(void)
{
	return _darkest_secret;
}
void		Contact::save_darkest_secret(std::string)
{
	std::cout << "Darkest secret: ";
	std::getline(std::cin, _darkest_secret, '\n');
}

void PhoneBook::add_contact(Contact &new_contact)
{
	if (contactCount < MAX_CONTACTS)
	{
		arr_contacts[contactCount] = new_contact;
		contactCount++;
	}
	else
	{
		std::cout << "El directorio está lleno. No se pueeden agragar más contactos" << std::endl;
	}
}

void PhoneBook::display_contacts()
{
	std::cout << "Lista de contactos: " << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "Contacto: " << i + 1 << ";" << std::endl;
		std::cout << "Nombre: " << arr_contacts[i].get_first_name() << std::endl;
        std::cout << "Apellido: " << arr_contacts[i].get_last_name() << std::endl;
        std::cout << "Apodo: " << arr_contacts[i].get_nickname() << std::endl;
        std::cout << "Teléfono: " << arr_contacts[i].get_phone_number() << std::endl;
        std::cout << "Secreto oscuro: " << arr_contacts[i].get_darkest_secret() << std::endl;
        std::cout << std::endl; // Separador entre contactos
	}
}

void    print_menu(void)
{
	std::cout << "**************** The very best Phonebook ***************" << std::endl;
	std::cout << std::endl;
	std::cout << "************* Type in one of the next commands: ********" << std::endl;
	std::cout << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::string menu_option;
	
//	std::system("clear");
	print_menu();
	while(1)
	{
		std::getline(std::cin, menu_option, '\n');
		if (menu_option == "ADD")
		{
			std::cout << "Has seleccionado: ADD" << std::endl;
			return (0);
		}
		else if (menu_option == "SEARCH")
		{
			for(int i = 0; i < 8; i++)
			{
				PhoneBook	phoneBook;
				phoneBook.adding_contact (Contact("0","0","0","0","0"));
			}
			std::cout << "has seleccionado: SEARCH" << std::endl;
			return (0);
		}
		else if (menu_option == "EXIT")
		{
			break;
		}
		else
		{
//				std::system("clear");
				print_menu();			
		}
	}
	return (0);
}