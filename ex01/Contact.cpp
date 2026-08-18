#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setFirstName(const std::string &str)
{
	_firstname = str;
}

void	Contact::setLastName(const std::string &str)
{
	_lastname = str;
}

void	Contact::setNickname(const std::string &str)
{
	_nickname = str;
}

void	Contact::setPhoneNumber(const std::string &str)
{
	_phoneNumber = str;
}

void	Contact::setDarkestSecret(const std::string &str)
{
	_darkest_secret = str;
}

std::string	Contact::getFirstName(void) const
{
	return _firstname;
}

std::string	Contact::getLastName(void) const
{
	return _lastname;
}

std::string	Contact::getNickname(void) const
{
	return _nickname;
}

std::string	Contact::getPhoneNumber(void) const
{
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const
{
	return _darkest_secret;
}

// True only if every field is still empty, i.e. the contact was never filled in.
bool	Contact::isEmpty(void) const
{
	return (_firstname.empty() && _lastname.empty() && _nickname.empty()
		&& _phoneNumber.empty() && _darkest_secret.empty());
}
