#ifndef BOOK_HPP
# define BOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>

const int MAX_CONTACTS = 8;
const int FIELD_WIDTH = 10;

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
	Contact 		contacts[MAX_CONTACTS];
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
void    	print_menu(void);

#endif