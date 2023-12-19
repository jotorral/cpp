#include "book.hpp"

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
	if (bookSize < MAX_CONTACTS)
		bookSize = contactCount + 1;
	contactCount = (contactCount + 1) % MAX_CONTACTS;
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
