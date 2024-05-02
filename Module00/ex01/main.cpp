#include "book.hpp"

PhoneBook::PhoneBook(void) : contactCount(0), bookSize(0)
{
//	std::cout << "Phonebook constructed" << std::endl;
};

PhoneBook::~PhoneBook(void)
{
//	std::cout << "Phonebook destructed" << std::endl;
};

Contact::Contact(void)
{
//	std::cout << "Contact constructed" << std::endl;
};

Contact::~Contact(void)
{
//	std::cout << "Contact destructed" << std::endl;
};

int main()
{
	PhoneBook myPhoneBook;
	std::string menu_option;
	std::string a, b, c, d, e;

	print_menu();
	while(1)
	{
		std::getline(std::cin, menu_option, '\n');
		if (std::cin.eof()==1) {
			return(0);
		}
		if (menu_option == "ADD")
		{
			std::cout << "Has seleccionado: ADD" << std::endl;
			myPhoneBook.addContact(a = "\0", b = "\0", c = "\0", d = "\0", e = "\0");
		}
		else if (menu_option == "SEARCH")
			myPhoneBook.displayContacts();
		else if (menu_option == "EXIT")
			break;
		else
			print_menu();
	}
	return (0);
}
