/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:02:20 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:23:56 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form() : name("Unnamed Form"), signingGradeRequired(1), executingGradeRequired(1)
{
    this->signedStatus = false;
}

Form::Form(std::string name) : name(name), signingGradeRequired(1), executingGradeRequired(1)
{
    this->signedStatus = false;
}

Form::Form(std::string name, const int signingGradeRequired, const int executingGradeRequired) : name(name), signingGradeRequired(signingGradeRequired), executingGradeRequired(executingGradeRequired)
{
    this->signedStatus = false;
    if (signingGradeRequired < 1 || executingGradeRequired < 1)
        throw Form::GradeTooHighException();
    else if (signingGradeRequired > 150 || executingGradeRequired > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    
}

Form::Form(Form const & src) : name(src.name), signingGradeRequired(src.signingGradeRequired), executingGradeRequired(src.executingGradeRequired)
{
    this->signedStatus = src.signedStatus;
}

const std::string Form::getName(void) const
{
    return (this->name);
}

bool Form::getSignedStatus(void) const
{
    return (this->signedStatus);
}

int Form::getSigningGradeRequired(void) const
{
    return (this->signingGradeRequired);
}

int Form::getExecutingGradeRequired(void) const
{
    return (this->executingGradeRequired);
}

void Form::beSigned(const Bureaucrat & bur)
{
    if (this->signedStatus)
        throw Form::AlreadySignedException();
    else if (bur.getGrade() <= this->signingGradeRequired)
        this->signedStatus = true;
    else
        throw Form::SigningGradeTooLowException();
}

// Extra for Ex02: add execute, which will call the executeSpecForm (which is implemented in child classes)
void                Form::execute(const Bureaucrat & executor) const
{
    if (executor.getGrade() <= this->getExecutingGradeRequired() && this->getSignedStatus() == true)
        this->executeSpecForm();
    else
        throw ExecuteFailureExeption();
}

// Exceptions
const char * Form::SigningGradeTooLowException::what() const throw ()
{
    return ("Need higher grade to sign this document");
}

const char * Form::GradeTooLowException::what() const throw ()
{
    return ("A grade needs to be between 1 and 150");
}

const char * Form::GradeTooHighException::what() const throw ()
{
    return ("A grade needs to be between 1 and 150");
}

const char * Form::AlreadySignedException::what() const throw ()
{
    return ("This form has already been signed");
}

const char * Form::ExecuteFailureExeption::what() const throw ()
{
    return ("This form cannot be executed because it has not been signed or the executor's rank is too low");
}

// Outside of class
std::ostream & operator<<(std::ostream &stdout, const Form &form)
{
    stdout << form.getName() << ", signing grade required: " << form.getSigningGradeRequired();
    return (stdout);
}