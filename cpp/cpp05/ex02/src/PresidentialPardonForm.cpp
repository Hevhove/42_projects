/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:57:51 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:24:34 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("default")
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target)
{
    
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : Form("PresidentialPardonForm", 25, 5), target(src.target)
{
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
    this->target = rhs.target;
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void)
{
    return (this->target);
}

void PresidentialPardonForm::executeSpecForm() const
{
    std::cout << this->target << " has been pardoned by Zaphod Breeblebox." << std::endl;
}

const char * PresidentialPardonForm::PresidentialPardonFailureException::what() const throw ()
{
    return ("Presidential Pardon could not be given");
}