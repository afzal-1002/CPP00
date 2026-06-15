#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->currentIndex = 0;
	this->totalContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::addNewContact(Contact contact)
{
	this->contacts[this->currentIndex] = contact;
	this->currentIndex = (this->currentIndex + 1) % 8;
	if (this->totalContacts < 8)
		this->totalContacts++;
	return (contact);
}

Contact PhoneBook::deleteContact(int contactId)
{
	int		i;
	Contact	deletedContact;

	if (contactId < 0 || contactId >= this->totalContacts)
	{
		std::cout << "Invalid Index" << std::endl;
		return (Contact());
	}
	deletedContact = this->contacts[contactId];
	i = contactId;
	while (i < this->totalContacts - 1)
	{
		this->contacts[i] = this->contacts[i + 1];
		i++;
	}
	this->totalContacts--;
	this->contacts[this->totalContacts] = Contact();
	this->currentIndex = this->totalContacts;
	return (deletedContact);
}

Contact PhoneBook::findByName(std::string name)
{
	int	i;

	i = 0;
	while (i < this->totalContacts)
	{
		if (this->contacts[i].getFirstName() == name)
			return (this->contacts[i]);
		i++;
	}
	return (Contact());
}

Contact PhoneBook::updateContact(int contactId, Contact contact)
{
	if (contactId < 0 || contactId >= this->totalContacts)
		return (Contact());
	this->contacts[contactId] = contact;
	return (this->contacts[contactId]);
}

int PhoneBook::getTotalLength()
{
	return (this->totalContacts);
}

int PhoneBook::getLastIndex()
{
	if (this->totalContacts == 0)
		return (-1);
	return (this->totalContacts - 1);
}

Contact PhoneBook::getContact(int index)
{
	if (index < 0 || index >= this->totalContacts)
		return (Contact());
	return (this->contacts[index]);
}

void PhoneBook::setContact(int index, Contact contact)
{
	if (index < 0 || index >= 8)
		return ;
	this->contacts[index] = contact;
}

void PhoneBook::addContact()
{
	Contact	contact;

	std::string input;
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "First Name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	contact.setFirstName(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Last Name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	contact.setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Nickname cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	contact.setNickName(input);
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Phone Number cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	contact.setPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Darkest Secret cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	contact.setDarkestSecret(input);
	addNewContact(contact);
	std::cout << "Contact Added Successfully" << std::endl;
}

std::string PhoneBook::truncateString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

std::string PhoneBook::centerString(std::string str)
{
	int	width;
	int	leftPadding;
	int	rightPadding;

	std::string fullText;
	width = 10;
	if ((int)str.length() >= width)
		return (str.substr(0, width));
	leftPadding = (width - str.length()) / 2;
	rightPadding = (width - str.length()) - leftPadding;
	fullText = std::string(leftPadding, ' ');
	fullText += str;
	fullText += std::string(rightPadding, ' ');
	return (fullText);
}

void PhoneBook::searchContact()
{
	int i;
	int index;
	Contact contact;

	if (this->totalContacts == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index"
				<< "|";
	std::cout << std::setw(10) << "First Name"
				<< "|";
	std::cout << std::setw(10) << "Last Name"
				<< "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	i = 0;
	while (i < this->totalContacts)
	{
		contact = this->contacts[i];

		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncateString(contact.getFirstName()) << "|";
		std::cout << std::setw(10) << truncateString(contact.getLastName()) << "|";
		std::cout << std::setw(10) << truncateString(contact.getNickName()) << std::endl;

		i++;
	}

	std::cout << "Enter Contact Index: ";
	std::cin >> index;
	std::cin.ignore();

	if (index < 0 || index >= this->totalContacts)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}

	contact = this->contacts[index];

	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}