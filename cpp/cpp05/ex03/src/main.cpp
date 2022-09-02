/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:51:33 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 16:21:00 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main(void)
{
    // Create bureaucrats
    Bureaucrat  bur1("George", 1);
    Bureaucrat  bur2("William", 100);

    // Create forms to be signed
    ShrubberyCreationForm   form1("My garden"); // (Sign: 145       Exec: 137)
    RobotomyRequestForm     form2("Toaster");   // (Sign: 72        Exec: 45)
    PresidentialPardonForm  form3("Hendrik");   // (Sign: 25        Exec: 5)

    // Sign forms
    std::cout << "[SIGNING FORMS]" << std::endl;
    bur1.signForm(form1);
    bur1.signForm(form2);
    bur2.signForm(form3); // fails -> signing level too low
    
    // Execute forms
    std::cout << std::endl << "[EXECUTING FORMS]" << std::endl;
    bur1.executeForm(form1);
    bur2.executeForm(form2); // fails -> executing level too low
    bur1.executeForm(form3); // fails -> has not been signed
    
    // Let's try again
    std::cout << std::endl << "[RETRYING]" << std::endl;
    bur1.executeForm(form2);
    bur1.signForm(form3);
    bur1.executeForm(form3);
    
    return (0);
}