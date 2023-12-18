#include <string>
#include <iostream>
#include <iomanip>

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
	int	bookSize;

public:
	PhoneBook(void);
	~PhoneBook(void);
	int main();
	void displayContacts(void);
	void addContact(std::string&, std::string&, std::string&, std::string&, std::string&);
	void displayOneContact ();
};

std::string str_truncate (const std::string& contact_field);
PhoneBook::PhoneBook(void) : contactCount(0), bookSize(0) {};
PhoneBook::~PhoneBook(void){};
Contact::Contact(void){};
Contact::~Contact(void){};
void    print_menu(void);

std::string str_truncate(const std::string& contact_field)
{
    int i;
    std::string strTrunc;

    for (i = 0; contact_field[i] != 0 && i < 9; ++i)
    {
        strTrunc += contact_field[i];
    }

    if (i == 9)
    {
        strTrunc += '.';
    }

    return strTrunc;
}


void PhoneBook::displayOneContact ()
{
	int	contactNumber;

	std::cin >> contactNumber;
	if (contactNumber < bookSize)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Index:          " << contactNumber << std::endl;
		std::cout << "First name:     " << str_truncate(contacts[contactNumber]._firstName) << std::endl;
		std::cout << "Last name:      " << contacts[contactNumber]._lastName << std::endl;
		std::cout << "Nickname:       " << contacts[contactNumber]._nickname << std::endl;
		std::cout << "Phone number:   " << contacts[contactNumber]._phoneNumber << std::endl;
		std::cout << "Darkest secret: " << contacts[contactNumber]._darkestSecret << std::endl << std::endl;
	}
	else
		{
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << "           |       NON EXISTING NUMBER       |" << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		return;
	}	
}

void PhoneBook::displayContacts()
{
	if (bookSize == 0)
	{
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << "           |  E M P T Y   P H O N E B O O K  |" << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		print_menu();
		return;
	}	
	std::cout << "Phone directory:\n";
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME|LAST NAME | NICKNAME |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < bookSize; ++i)
	{
		std::cout << "|" << std::setiosflags(std::ios::right) << std::setw(10) << i << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << contacts[i]._firstName << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << contacts[i]._lastName << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << contacts[i]._nickname << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
	std::cout << "Type in the index number you wish to see: ";
	displayOneContact ();
}

void PhoneBook::addContact(std::string& _name, std::string& _last, std::string& _nick, std::string& _phone, std::string& _secret)
{
	std::cout << "Index:          " << contactCount << std::endl;
	std::cout << "Name:           ";
	std::cin >> _name;
	contacts[contactCount]._firstName = _name;
	std::cout << "Last name:      ";
	std::cin >> _last;
	contacts[contactCount]._lastName = _last;
	std::cout << "Nickname:       ";
	std::cin >> _nick;
	contacts[contactCount]._nickname = _nick;
	std::cout << "Phone number:   ";
	std::cin >> _phone;
	contacts[contactCount]._phoneNumber = _phone;
	std::cout << "Darkest secret: ";
	std::cin >> _secret;
	contacts[contactCount]._darkestSecret = _secret;
	if (bookSize < 8)
		bookSize = contactCount + 1;
	contactCount = (contactCount + 1) % 8;
	std::cout << "Contacto agregado correctamente.\n";
}

void    print_menu(void)
{
	std::cout << std::endl;
	std::cout << "********************************************************" << std::endl;
	std::cout << "**************** The very best Phonebook ***************" << std::endl;
	std::cout << "********************************************************" << std::endl;
	std::cout << "*                                                      *" << std::endl;
	std::cout << "*         Type in one of the next commands:            *" << std::endl;
	std::cout << "*                                                      *" << std::endl;
	std::cout << "*         ADD                                          *" << std::endl;
	std::cout << "*         SEARCH                                       *" << std::endl;
	std::cout << "*         EXIT                                         *" << std::endl;
	std::cout << "*                                                      *" << std::endl;	
	std::cout << "********************************************************" << std::endl;	
	std::cout << std::endl;
}

int main()
{
	PhoneBook myPhoneBook;
	std::string menu_option;
	std::string a, b, c, d, e;

//	myPhoneBook.contactCount = 0;
//	int	bookSize;

	print_menu();
	while(1)
	{
		std::getline(std::cin, menu_option, '\n');
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
