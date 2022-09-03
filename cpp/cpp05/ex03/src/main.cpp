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
#include "../inc/Intern.hpp"

int	main(void)
{
	Intern someRandomIntern;
	Form* form;
    Bureaucrat bur1("Harry", 1);

	form = someRandomIntern.makeForm("presidential pardon", "Bender");
    bur1.signForm(*form);
    bur1.executeForm(*form);
	delete form;
	
	form = someRandomIntern.makeForm("robotomy request", "Bender");
    bur1.signForm(*form);
    bur1.executeForm(*form);
	delete form;

	form = someRandomIntern.makeForm("shrubbery creation", "Bender");
    bur1.signForm(*form);
    bur1.executeForm(*form);
	delete form;

	form = someRandomIntern.makeForm("earth destruction request form", "Bender");
    delete form;

	return (0);
}