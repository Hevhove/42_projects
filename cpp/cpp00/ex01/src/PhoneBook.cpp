/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:02:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/05 13:23:40 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myawesomephonebook.hpp"

PhoneBook::PhoneBook(){
    index = 0;
    numContacts = 0;
    return ;
};

PhoneBook::~PhoneBook(){
    //
};

void    PhoneBook::addContact(void){
    if (index >= MAX_CONTACTS)
        index = 0;
	std::cout << " " << std::endl;
	contacts[index].setFirstName();
	contacts[index].setLastName();
	contacts[index].setNickName();
	contacts[index].setPhoneNumber();
	contacts[index].setDarkSecret();
	index++;
	if (numContacts < 8)
		numContacts++;
	std::cout << "-> Contact added successfully!" << std::endl;
	std::cout << " " << std::endl;
}

void    PhoneBook::displayContacts(){
	std::cout << std::endl << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i <  MAX_CONTACTS; i++)
	{
		std::cout << "|         " << i + 1;
		std::cout << "|" << contacts[i].formatContact(contacts[i].getFirstName());
		std::cout << "|" << contacts[i].formatContact(contacts[i].getLastName());
		std::cout << "|" << contacts[i].formatContact(contacts[i].getNickName()) << "|";
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void    PhoneBook::displayInfo(int index){

    std::cout << "| First Name:    " << contacts[index - 1].getFirstName() << std::endl;
	std::cout << "| Last Name:     " << contacts[index - 1].getLastName() << std::endl;
	std::cout << "| Nickname:      " << contacts[index - 1].getNickName() << std::endl;
	std::cout << "| Phone Number:  " << contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << "| Dark Secret:   " << contacts[index - 1].getDarkSecret() << std::endl;
	std::cout << std::endl;
}
