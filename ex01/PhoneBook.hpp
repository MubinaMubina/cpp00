#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_totalCount;
	int		_oldestIndex;

	void	_displaySummaryTable(void) const;
	void	_displayContactDetail(int index) const;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContact(void) const;
};

#endif

