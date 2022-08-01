/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:46:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/01 19:28:40 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myawesomephonebook.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string buff;
    
    (void)phonebook;
    // Welcoming message
    std::cout << "[=================================]" << std::endl;
    std::cout << " Welcome to the awesome phonebook! " << std::endl;
    std::cout << " Actions: ADD | SEARCH | EXIT " << std::endl;
    std::cout << "[=================================]" << std::endl;
    std::cout << " Enter action: ";
    // while the input is not EXIT, make some loop
    std::cin >> buff;
    std::cout << " Selected action is: " << buff << std::endl;
    std::cout << "[=================================]" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return (0);
}