/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:50:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/02 17:11:48 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myawesomephonebook.hpp"
#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(){
    this->contacts_added = 0;
    std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook(){
    std::cout << "PhoneBook deleted" << std::endl;
}

void    PhoneBook::add(){
    std::string input;

    std::cout << "Enter First Name: ";
    std::cin >> input;
    contacts[contacts_added % 8].setFirstName(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    std::cout << "Enter Last Name: ";
    std::cin >> input;
    contacts[contacts_added % 8].setLastName(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    std::cout << "Enter Nickname: ";
    std::cin >> input;
    contacts[contacts_added % 8].setNickName(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    std::cout << "Enter Phone Number: ";
    std::cin >> input;
    contacts[contacts_added % 8].setPhoneNumber(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    std::cout << "Enter Darkest Secret: ";
    std::cin >> input;
    contacts[contacts_added % 8].setSecret(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    this->contacts_added++;
}