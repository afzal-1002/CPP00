#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
  private:
	Contact contacts[8];
	int currentIndex;
	int totalContacts;

  public:
	PhoneBook();
	~PhoneBook();

	Contact addNewContact(Contact contact);
	Contact deleteContact(int contactId);
	Contact findByName(std::string name);
	Contact updateContact(int contactId, Contact contact);

	int getTotalLength();
	int getLastIndex();

	Contact getContact(int index);
	void setContact(int index, Contact contact);

	void addContact();
	void searchContact();

	std::string truncateString(std::string str);
	std::string centerString(std::string str);
};

#endif