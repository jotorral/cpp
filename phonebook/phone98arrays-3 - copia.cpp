#include <iostream>
#include <string>

class Contact
{
public:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

	Contact(void);
	~Contact(void);
};

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook(void);
	~PhoneBook(void);
	void displayContacts(void);
	void addContact(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
};

PhoneBook::PhoneBook(void){};
PhoneBook::~PhoneBook(void){};
Contact::Contact(void){};
Contact::~Contact(void){};

void PhoneBook::displayContacts()
{
	std::cout << "Libro de Teléfonos:\n";
	for (int i = 0; i < contactCount; ++i)
	{
		std::cout << "Index: " << i << "\t Nombre: " << contacts[i]._firstName << "\t Teléfono: " << contacts[i]._phoneNumber << "\n";
	}
}

void PhoneBook::addContact(const std::string& _name, const std::string& _last, const std::string& _nick, const std::string& _phone, const std::string& _secret)
{
	if (contactCount < 8) {
		contacts[contactCount]._firstName = _name;
		contacts[contactCount]._firstName = _last;
		contacts[contactCount]._lastName = _nick;
		contacts[contactCount]._phoneNumber = _phone;
		contacts[contactCount]._darkestSecret = _secret;
		++contactCount;
		std::cout << "Contacto agregado correctamente.\n";
	}
	else
	{
		std::cout << "El libro de teléfonos está lleno. No se puede agregar más contactos.\n";
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

int main()
{
	PhoneBook myPhoneBook;
	std::string menu_option;

	myPhoneBook.addContact("Nombre1", "Apellido1", "Mote1", "123-456-7890", "Secreto más oscuro1");
	myPhoneBook.addContact("Nombre2", "Apellido2", "Mote2", "987-654-3210", "Secreto más oscuro2");
	myPhoneBook.addContact("Nombre3", "Apellido3", "Mote3", "111-222-3333", "Secreto más oscuro3");
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
			myPhoneBook.displayContacts();
//			std::cout << "has seleccionado: SEARCH" << std::endl;
//			return (0);
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
