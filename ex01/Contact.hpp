#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>

struct Contact
{
private:
    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _darkest_secret;
    std::string _phoneNumber;

public:
    Contact(void);
    ~Contact(void);

    void		setFirstName(const std::string &str);
	void		setLastName(const std::string &str);
	void		setNickname(const std::string &str);
	void		setPhoneNumber(const std::string &str);
	void		setDarkestSecret(const std::string &str);

	// Getters
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

	bool		isEmpty(void) const;
};

#endif