/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:53:13 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 17:45:38 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_INTERN_HPP
# define CLASS_INTERN_HPP
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    private:
        
    public:
        // Constructors
        Intern();
        ~Intern();
        Intern(const Intern & src);
        Intern& operator=(const Intern & rhs);

        // Member functions
        Form*  makeForm(std::string name, std::string target);
        Form* 	makeShrubberyCreation(const std::string &target);
        Form* 	makeRobotomyRequest(const std::string &target);
        Form* 	makePresidentialPardon(const std::string &target);

        // Exceptions
        class FormNameDoesNotExist : public std::exception {
            const char * what () const throw ();
        };
};

#endif