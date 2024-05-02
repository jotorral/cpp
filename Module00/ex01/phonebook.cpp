#include "book.hpp"

std::string	Contact::getInfo (std::string type){
	if (type == "first")
		return (this->_firstName);
	if (type == "last")
		return (this->_lastName);
	if (type == "nick")
		return (this->_nickname);
	if (type == "phone")
		return (this->_phoneNumber);
	if (type == "darkest")
		return (this->_darkestSecret);
return(0);
}

void		Contact::setInfo (std::string type, std::string data){
	if (type == "first")
		this->_firstName = data;
	if (type == "last")
		this->_lastName = data;
	if (type == "nick")
		this->_nickname = data;
	if (type == "phone")
		this->_phoneNumber = data;
	if (type == "darkest")
		this->_darkestSecret = data;
}

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
		std::cout << "First name:     " << contacts[(int)contactNumber].getInfo("first") << std::endl;
		std::cout << "Last name:      " << contacts[(int)contactNumber].getInfo("last") << std::endl;
		std::cout << "Nickname:       " << contacts[(int)contactNumber].getInfo("nick") << std::endl;
		std::cout << "Phone number:   " << contacts[(int)contactNumber].getInfo("phone") << std::endl;
		std::cout << "Darkest secret: " << contacts[(int)contactNumber].getInfo("darkest") << std::endl << std::endl;
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
			<< std::setiosflags(std::ios::right) << std::setw(10) << &str_truncate(contacts[i].getInfo("first"))[0] << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << &str_truncate(contacts[i].getInfo("last"))[0] << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10) << &str_truncate(contacts[i].getInfo("nick"))[0] << "|" << std::endl;
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
	contacts[contactCount].setInfo("first", _name);
	std::cout << "Last name:      ";
	std::getline(std::cin, _last);
	while (_last[0] == '\0')
	{
		std::cout << "Last name:      ";
		std::getline(std::cin, _last);
	}	
	contacts[contactCount].setInfo("last", _last);
	std::cout << "Nickname:       ";
	std::getline(std::cin, _nick);
	while (_nick[0] == '\0')
	{
		std::cout << "Nickname:       ";
		std::getline(std::cin, _nick);
	}	
	contacts[contactCount].setInfo("nick", _nick);
	std::cout << "Phone number:   ";
	std::getline(std::cin, _phone);
	while (_phone[0] == '\0')
	{
		std::cout << "Phone number:   ";
		std::getline(std::cin, _phone);
	}
	contacts[contactCount].setInfo("phone", _phone);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, _secret);
	while (_secret[0] == '\0')
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, _secret);
	}	
	contacts[contactCount].setInfo("darkest", _secret);
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
