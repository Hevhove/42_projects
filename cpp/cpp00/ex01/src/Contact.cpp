/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:51:18 by Hendrik           #+#    #+#             */
/*   Updated: 2022/08/05 13:34:59 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"

// Constructors
Contact::Contact(){}
Contact::~Contact(){}

/*
	SETTERS & GETTERS:

	Below functions are setters and getters of the variables contained within a contact.
	Using these functions, we can set the variables and retrieve the variables directly
	from the PhoneBook class instance, without accessing the contacts directly.
*/

void	Contact::setFirstName(void) {
	std::cout << "First Name:     ";
	std::getline(std::cin, firstName);
	while (firstName.empty())
	{
		std::cout << "Please enter a name..." << std::endl;
		std::getline(std::cin, firstName);
	}
}

void	Contact::setLastName(void) {
	std::cout << "Last Name:      ";
	std::getline(std::cin, lastName);
	while (lastName.empty())
	{
		std::cout << "Please enter a name..." << std::endl;
		std::getline(std::cin, lastName);
	}
}

void	Contact::setNickName(void) {
	std::cout << "Nickname:       ";
	std::getline(std::cin, nickName);
	while (nickName.empty())
	{
		std::cout << "Please enter a name..." << std::endl;
		std::getline(std::cin, nickName);
	}
}

void	Contact::setPhoneNumber(void) {
	std::cout << "Phone Number:   ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.empty())
	{
		std::cout << "Please enter a number..." << std::endl;
		std::getline(std::cin, phoneNumber);
	}
}

void	Contact::setDarkSecret(void) {
	std::cout << "Dark Secret:    ";
	std::getline(std::cin, darkSecret);
	while (darkSecret.empty())
	{
		std::cout << "Please enter your secret..." << std::endl;
		std::getline(std::cin, darkSecret);
	}
}

// GETTERS
std::string Contact::getFirstName(void) {
	return this->firstName;
}

std::string Contact::getLastName(void) {
	return this->lastName;
}

std::string Contact::getNickName(void) {
	return this->nickName;
}

std::string Contact::getPhoneNumber(void) {
	return this->phoneNumber;
}

std::string Contact::getDarkSecret(void) {
	return this->darkSecret;
}

/*
	Other useful functions for formatting
*/
std::string Contact::formatContact(std::string str) {
	int diff;

	diff = 10 - str.length();
	if (diff > 0)
	{
		for (int i = 0; i < diff; i++)
			str.insert(0, " ");
	}
	else if (diff < 0)
	{
		str[9] = '.';
		str = str.substr(0, 10);
	}
	return (str);
}
