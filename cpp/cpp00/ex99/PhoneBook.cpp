/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:02:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/03 12:39:53 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    index = 0;
    numContacts = 0;
    return ;
};

PhoneBook::~PhoneBook(){
    //
};

void    PhoneBook::addContact(void){
    if (index >= MAX_SIZE)
        index = 0;
}

void    PhoneBook::displayContacts(){
    std::cout << "test" << std::endl;
}

void    PhoneBook::displayInfo(int index){
    std::cout << "test" << std::endl;    
}