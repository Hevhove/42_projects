/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:03:19 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:24:46 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:48:48 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 13:03:07 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("default")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : Form("ShrubberyCreationForm", 145, 137), target(src.target)
{
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
    this->target = rhs.target;
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void)
{
    return (this->target);
}

void ShrubberyCreationForm::executeSpecForm() const
{
    std::ofstream   of1;
    std::string     outfile_name;

    outfile_name = this->target + "_shrubbery";
    of1.open(outfile_name.c_str());

    if (!of1)
        throw ShrubberyCreationFailureException();
    of1 << std::endl;
    of1 << "                 .o00o                " << std::endl;
    of1 << "               o000000oo              " << std::endl;
    of1 << "              00000000000o            " << std::endl;
    of1 << "             00000000000000           " << std::endl;
    of1 << "          oooooo  00000000  o88o      " << std::endl;
    of1 << "       ooOOOOOOOoo  ```''  888888     " << std::endl;
    of1 << "     OOOOOOOOOOOO'.qQQQQq. `8888'     " << std::endl;
    of1 << "    oOOOOOOOOOO'.QQQQQQQQQQ/.88'      " << std::endl;
    of1 << "    OOOOOOOOOO'.QQQQQQQQQQ/ /q145           " << std::endl;
    of1 << "               |  | O| |              " << std::endl;
    of1 << "       _       /\\. \\_/ /\\             " << std::endl;
    of1 << "        `---__/|_\\   //|  __         " << std::endl;
    of1 << "              `-'  `-'`-'-'           " << std::endl;
    of1 << std::endl;

    of1.close();
    std::cout << "Shrubbery was created in file: " << outfile_name << std::endl;
}

const char * ShrubberyCreationForm::ShrubberyCreationFailureException::what() const throw ()
{
    return ("Shrubbery Creation failed.");
}