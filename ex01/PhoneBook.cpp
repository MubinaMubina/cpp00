#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void) : _totalCount(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

// Truncates strings longer than 10 chars to 9 chars + '.'
static std::string truncateString(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

// Helper to prompt for non-empty input
static std::string getInput(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return "";
        if (!input.empty())
            return input;
        std::cout << "Field cannot be empty. Please try again.\n";
    }
}

void PhoneBook::addContact(void)
{
    Contact     newContact;
    std::string input;

    std::cout << "\n--- ADD NEW CONTACT ---\n";
    
    input = getInput("First Name: ");
    if (input.empty()) return;
    newContact.setFirstName(input);

    input = getInput("Last Name: ");
    if (input.empty()) return;
    newContact.setLastName(input);

    input = getInput("Nickname: ");
    if (input.empty()) return;
    newContact.setNickname(input);

    input = getInput("Phone Number: ");
    if (input.empty()) return;
    newContact.setPhoneNumber(input);

    input = getInput("Darkest Secret: ");
    if (input.empty()) return;
    newContact.setDarkestSecret(input);

    // If phonebook has fewer than 8 contacts, fill next available slot
    if (_totalCount < 8)
    {
        _contacts[_totalCount] = newContact;
        _totalCount++;
    }
    // If full (8 contacts), overwrite the oldest contact and increment oldest index
    else
    {
        _contacts[_oldestIndex] = newContact;
        _oldestIndex = (_oldestIndex + 1) % 8;
    }

    std::cout << "Contact successfully saved!\n\n";
}

void PhoneBook::_displaySummaryTable(void) const
{
    std::cout << "=============================================\n";
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << "|\n";
    std::cout << "=============================================\n";

    for (int i = 0; i < _totalCount; ++i)
    {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << truncateString(_contacts[i].getFirstName())
                  << "|" << std::setw(10) << truncateString(_contacts[i].getLastName())
                  << "|" << std::setw(10) << truncateString(_contacts[i].getNickname())
                  << "|\n";
    }
    std::cout << "=============================================\n";
}

void PhoneBook::_displayContactDetail(int index) const
{
    std::cout << "\n--- CONTACT DETAILS (Index " << index << ") ---\n";
    std::cout << "First Name:     " << _contacts[index].getFirstName() << "\n";
    std::cout << "Last Name:      " << _contacts[index].getLastName() << "\n";
    std::cout << "Nickname:       " << _contacts[index].getNickname() << "\n";
    std::cout << "Phone Number:   " << _contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << "\n\n";
}

void PhoneBook::searchContact(void) const
{
    if (_totalCount == 0)
    {
        std::cout << "PhoneBook is currently empty.\n\n";
        return;
    }

    _displaySummaryTable();

    std::string input;
    std::cout << "Enter the index of the contact to display: ";
    if (!std::getline(std::cin, input))
        return;

    // Validate if single digit and within range
    if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + _totalCount)
    {
        int index = input[0] - '0';
        _displayContactDetail(index);
    }
    else
    {
        std::cout << "Invalid index! Please enter a valid index from the table.\n\n";
    }
}
