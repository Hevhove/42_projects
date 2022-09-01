/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:51:33 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/01 17:42:18 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    // Create bureaucrats and forms
    Bureaucrat  bur1("George", 1);
    Bureaucrat  bur2("William", 20);
    Form        form1("Random Form", 10, 100);
    Form        form2("Important Form", 5, 100);
    
    // Create a wrong Form    
    try {
        Form        form2("Another random Form", -1, 150);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // George can sign the form, no problem
    try {
        bur1.signForm(form1);
        bur2.signForm(form1); // has already been signed -> exception, even if bur2's grade is too low!
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Bur2 really wants to sign a document... Will he succeed?
    try {
        bur2.signForm(form2);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}