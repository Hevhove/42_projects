/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:46:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/02 17:07:51 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myawesomephonebook.hpp"

void    display_welcome(void)
{
    std::cout << "[=================================]" << std::endl;
    std::cout << " Welcome to the awesome phonebook! " << std::endl;
    return ;
}

std::string    get_action(void)
{
    std::string buff;
    
    std::cout << " Actions: ADD | SEARCH | EXIT " << std::endl;
    std::cout << "[=================================]" << std::endl;
    std::cout << " Enter action: ";
    std::cin >> buff;
    std::cout << " Selected: " << buff << std::endl;
    std::cout << "[=================================]" << std::endl;
    return (buff);
}

std::string get_info(const std::string datapoint)
{
    std::string buff;
    std::cout << datapoint << ": ";
    std::cin >> buff;
    std::cout << std::endl;
    return (buff);
}

// void    add_contact(PhoneBook *phonebook)
// {
//     std::cout << "Please enter information: " << std::endl;
//     phonebook.firstname = get_info("First Name");
//     phonebook.lastname = get_info("Last Name");
//     phonebook.nickname = get_info("Nickname");
//     phonebook.phonenumber = get_info("Phone Number");
//     phonebook.phonenumber = get_info("Darkest Secret");
// }

int main(void)
{
    PhoneBook   phonebook;
    std::string input;
    
    display_welcome();
    while (true)
    {
        input = get_action();
        if (input.compare("ADD") == 0)
            phonebook.add();
        else if (input.compare("SEARCH") == 0)
            ;//phonebook.search();
        else if (input.compare("EXIT") == 0)
        {
            std::cout << "Thanks for using the awesome phonebook!" << std::endl;
            break ;
        }
        else
            std::cout << "Please provide a valid input..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return (0);
}