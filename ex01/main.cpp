#include "PhoneBook.hpp"
#include <cctype>

static std::string toUpper(std::string str)
{
	int	i;

	i = 0;
	while (i < (int)str.length())
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

static void	printMenu(void)
{
	std::cout << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "||   PHONEBOOK   ||" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "|| 01. ADD       ||" << std::endl;
	std::cout << "|| 02. SEARCH    ||" << std::endl;
	std::cout << "|| 03. DELETE    ||" << std::endl;
	std::cout << "|| 04. EXIT      ||" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "Select Option (ADD/01): ";
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string command;
	int index;

	while (true)
	{
		printMenu();

		std::cout << "Command: ";

		if (!std::getline(std::cin, command))
			break ;

		command = toUpper(command);

		if (command == "ADD" || command == "01" || command == "1")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH" || command == "02" || command == "2")
		{
			phoneBook.searchContact();
		}
		else if (command == "DELETE" || command == "03" || command == "3")
		{
			phoneBook.searchContact();
			std::cout << "Index: ";

			if (!(std::cin >> index))
				break ;
			std::cin.ignore();

			if (phoneBook.deleteContact(index).getFirstName().empty())
				std::cout << "Delete operation failed." << std::endl;
			else
				std::cout << "Delete operation completed." << std::endl;
		}
		else if (command == "EXIT" || command == "04")
		{
			std::cout << "Good Bye!" << std::endl;
			break ;
		}
		else if (!command.empty())
		{
			std::cout << "Unknown Command" << std::endl;
		}
	}

	return (0);
}