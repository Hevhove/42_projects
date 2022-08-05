/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:57:30 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/05 13:32:14 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"

int main(void)
{
    PhoneBook       phonebook;
    std::string     input;
    int             id;

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
            while (std::cin.fail() || id < 1 || id > 8)
            {
                std::cout << "> Please provide a number between 1 and 8" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cin >> id;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            phonebook.displayInfo(id);
        }
        else if (input.compare("EXIT") == 0)
            return (0);
        else
            std::cout << "> Please enter a valid command [ADD | SEARCH | EXIT]" << std::endl;
    }
}
