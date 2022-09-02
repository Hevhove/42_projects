/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:18 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 13:36:55 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BUREAUCRAT_HPP
# define CLASS_BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;

    public:
        // Canonical Constructors
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat& operator=(Bureaucrat const & rhs);

        // Accessors
        const std::string   getName(void) const;
        int                 getGrade(void) const;

        // Increment/Decrement
        void                incrementGrade(void);
        void                decrementGrade(void);

        // Exceptions
        class GradeTooHighException : public std::exception {
            const char * what () const throw();
        };
        class GradeTooLowException : public std::exception {
            const char * what () const throw();
        };

        // Additional for ex01
        void    signForm(Form & form);

        // Additional for ex02;
        void    executeForm(Form const & form);
};

std::ostream & operator << (std::ostream &stdout, const Bureaucrat &bureaucrat);

#endif