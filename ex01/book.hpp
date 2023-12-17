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
	Contact(void);
	~Contact(void);
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	std::string	get_first_name(void);
	void		save_first_name(std::string);
	std::string	get_last_name(void);
	void		save_last_name(std::string);	
	std::string	get_nickname(void);
	void		save_nickname(std::string);
	std::string	get_phone_number(void);
	void		save_phone_number(std::string);	
	std::string	get_darkest_secret(void);
	void		save_darkest_secret(std::string);
};

class   PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(Contact &);
	void	display_contacts();
	void	adding_contact(const Contact& contact){};

private:

	Contact	arr_contacts[MAX_CONTACTS];
	int		contactCount;
};


#endif