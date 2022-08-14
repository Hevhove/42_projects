/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:52:19 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/13 11:41:58 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "The memory address of the string variable:   " << &string << std::endl;
    std::cout << "The memory address held by stringPTR:        " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF:        " << &stringREF << std::endl;
    
    std::cout << "---" << std::endl;

    std::cout << "The value of the string variable:            " << string << std::endl;
    std::cout << "The value pointed to by stringPTR:           " << *stringPTR << std:: endl;
    std::cout << "The value pointed to by stringREF:           " << stringREF << std::endl;
    
    return (0);
}