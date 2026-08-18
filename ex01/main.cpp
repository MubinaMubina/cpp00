#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break; // stream failed / EOF — decide if this should just stop the loop

        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
        // else: silently ignore, per spec ("Any other input is ignored.")
    }
    return 0;
}
