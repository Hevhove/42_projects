/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:57:30 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/03 12:33:51 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool valid_index(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
            return (false);
    }
    return true;
}

int main(void)
{
    PhoneBook       phonebook;
    std::string     input;
    int             id;
    int             result;
    
    while (true)
    {
        std::cout << "Select Option:\n[ADD] contact | [SEARCH] contact | [EXIT] program" << std::endl;
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
            phonebook.addContact();
        else if (input.compare("SEARCH") == 0)
        {
            phonebook.displayContacts();
            std::cout << "Enter userID to receive more information" << std:: endl;
            std::cin >> id;
            while (std::cin.fail())
            {
                std::cout << "Please provide a number" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cin >> id;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            phonebook.displayInfo(id);
        }
        else if (input.compare("EXIT") == 0)
        {
            std::cout << "Thank you, come again!" << std::endl;
            return (0);
        }
        else
            std::cout << "Please enter a valid command [ADD | SEARCH | EXIT]" << std::endl;
    }
}