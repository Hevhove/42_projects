/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:45:36 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/01 16:16:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("Unkown Bureaucrat"), grade(150)
{
    
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name), grade(src.grade)
{
    
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs)
{
    this->grade = rhs.grade;
    return (*this);
}

// Member functions
const std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade++;
}

void Bureaucrat::signForm(Form & form)
{
    if (form.signedStatus == true)
        throw Form::AlreadySignedException();
    else if (this->grade > signingGradeRequired && form.signedStatus == false)
    {
        std::cout << *this << " has signed the form " <<  form << std::endl;
        form.signedStatus = true;
    }

    else
        throw Bureaucrat::GradeTooLowException();
    
}

const char * Bureaucrat::GradeTooHighException::what() const throw ()
{   
    return ("Grade too low");
}

const char * Bureaucrat::GradeTooLowException::what() const throw ()
{
    return ("Grade too high");
}

std::ostream & operator<<(std::ostream &stdout, const Bureaucrat &bur)
{
    stdout << bur.getName() << ", grade: " << bur.getGrade();
    return (stdout);
}