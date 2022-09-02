/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:48:48 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:28:57 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("default")
{
    
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : Form("RobotomyRequestForm", 72, 45), target(src.target)
{
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
    this->target = rhs.target;
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void)
{
    return (this->target);
}

void RobotomyRequestForm::executeSpecForm() const
{
    std::cout << "* Drilling Noises *" << std::endl;
    srand(time(0)); // set random seed to current time
    const float randomNumber = (float) rand() / RAND_MAX; // generate random number between 0 and 1
    if (randomNumber >= 0.50)
        std::cout << this->target << " has been robotomized." << std::endl;
    else
        throw RobotomyRequestFailureException();
}

const char * RobotomyRequestForm::RobotomyRequestFailureException::what() const throw ()
{
    return ("Robotomy Request failed due to hardware disruption. Try again later");
}