/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:04:12 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 17:48:50 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

// Constructors
Intern::Intern()
{
    
}

Intern::~Intern()
{
    
}

Intern::Intern(const Intern & src)
{
    (void)src;
}

Intern& Intern::operator=(const Intern & rhs)
{
    (void)rhs;
    return (*this);
}

// Member functions
Form* Intern::makeForm(std::string name, std::string target)
{
    std::string availableForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    // The below line creates an array of 3 pointers to member functions
    Form* (Intern::*forms[3])(const std::string&) = {&Intern::makeShrubberyCreation, &Intern::makeRobotomyRequest, &Intern::makeShrubberyCreation};
    int i;
    for (i = 0; i < 3; i++)
    {
        if (name.compare(availableForms[i]) == 0)
            break ;
    }
    try {
            if (i < 3)
                return ((this->*(forms[i]))(target));
            else
                throw Intern::FormNameDoesNotExist();
    } 
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (0);
    }
}

Form* 	Intern::makeShrubberyCreation(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form* 	Intern::makeRobotomyRequest(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form* 	Intern::makePresidentialPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

// Exceptions
const char * Intern::FormNameDoesNotExist::what() const throw ()
{
    return ("Form name does not exist");
}
