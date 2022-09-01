/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:51:33 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/01 13:15:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    // 3 bureaucrats -> no problem!
    Bureaucrat  bur1("George", 5);
    Bureaucrat  bur2("William", 1);
    Bureaucrat  bur3("Margaret", 150);

    // 2 bureaucrats that cannot be created
    try
    {
        Bureaucrat bur4("Daniel", -1);
        Bureaucrat bur5("Harry", 160); // this will not be executed
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    // Let's increment and decrement a bit...
    bur1.decrementGrade();
    std::cout << bur1 << std::endl; // showcasing the << overload
    bur1.incrementGrade();
    std::cout << bur1 << std::endl;
    // This will fail...
    try
    {
        bur2.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // This too...
    try
    {
        bur3.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}