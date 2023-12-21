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
	Contact 		contacts[8];
	unsigned int 	contactCount;
	unsigned int	bookSize;

public:
	PhoneBook(void);
	~PhoneBook(void);
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
	unsigned int	i;
	std::string strTrunc;

	for (i = 0; contact_field[i] != 0;i++)
	{
		if (i > 9)
		{
			strTrunc[i - 1] = '.';
			break;
		}
		strTrunc[i] = contact_field[i];
	}
	strTrunc[i] = '\0';
	return (strTrunc);
}


void PhoneBook::displayOneContact ()
{
	char	contactNumber;

	std::cin >> contactNumber;
	contactNumber = contactNumber - '0';
	if ((unsigned int)contactNumber < bookSize && (unsigned int)contactNumber >= 0)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Index:          " << (char)(contactNumber + '0') << std::endl;
		std::cout << "First name:     " << contacts[(int)contactNumber]._firstName << std::endl;
		std::cout << "Last name:      " << contacts[(int)contactNumber]._lastName << std::endl;
		std::cout << "Nickname:       " << contacts[(int)contactNumber]._nickname << std::endl;
		std::cout << "Phone number:   " << contacts[(int)contactNumber]._phoneNumber << std::endl;
		std::cout << "Darkest secret: " << contacts[(int)contactNumber]._darkestSecret << std::endl << std::endl;
	}
	else
		{
		std::cout << "\n\n\n\n\n" << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << "           |       NON EXISTING NUMBER       |" << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << "\n\n\n\n\n" << std::endl;
		return;
	}	
}

void PhoneBook::displayContacts()
{
	if (bookSize == 0)
	{
		std::cout << "\n\n\n\n\n" << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << "           |  E M P T Y   P H O N E B O O K  |" << std::endl;
		std::cout << "           -----------------------------------" << std::endl;
		std::cout << "\n\n\n\n\n" << std::endl;
		print_menu();
		return;
	}	
	std::cout << "Phone directory:\n";
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME|LAST NAME | NICKNAME |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (unsigned int i = 0; i < bookSize; ++i)
	{
		std::cout << "|" << std::setiosflags(std::ios::right) << std::setw(10) << i << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << &str_truncate(contacts[i]._firstName)[0] << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << &str_truncate(contacts[i]._lastName)[0] << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << &str_truncate(contacts[i]._nickname)[0] << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
	std::cout << "Type in the index number you wish to see: ";
	displayOneContact ();
}

void PhoneBook::addContact(std::string& _name, std::string& _last, std::string& _nick, std::string& _phone, std::string& _secret)
{
	std::cout << "Index:          " << contactCount << std::endl;
	std::cout << "Name:           ";
	std::getline(std::cin, _name);
	while (_name[0] == '\0')
	{
		std::cout << "Name:           ";
		std::getline(std::cin, _name);
	}
	contacts[contactCount]._firstName = _name;
	std::cout << "Last name:      ";
	std::getline(std::cin, _last);
	while (_last[0] == '\0')
	{
		std::cout << "Last name:      ";
		std::getline(std::cin, _last);
	}	
	contacts[contactCount]._lastName = _last;
	std::cout << "Nickname:       ";
	std::getline(std::cin, _nick);
	while (_nick[0] == '\0')
	{
		std::cout << "Nickname:       ";
		std::getline(std::cin, _nick);
	}	
	contacts[contactCount]._nickname = _nick;
	std::cout << "Phone number:   ";
	std::getline(std::cin, _phone);
	while (_phone[0] == '\0')
	{
		std::cout << "Phone number:   ";
		std::getline(std::cin, _phone);
	}
	contacts[contactCount]._phoneNumber = _phone;
	std::cout << "Darkest secret: ";
	std::getline(std::cin, _secret);
	while (_secret[0] == '\0')
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, _secret);
	}	
	contacts[contactCount]._darkestSecret = _secret;
	if (bookSize < 8)
		bookSize = contactCount + 1;
	contactCount = (contactCount + 1) % 8;
	std::cout << "\n\n\nContact successfully added.\n\n\n" << std::endl;
	print_menu();
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
