/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:19:18 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/01 13:10:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BUREAUCRAT_HPP
# define CLASS_BUREAUCRAT_HPP
# include <iostream>
# include <exception>

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
};

std::ostream & operator << (std::ostream &stdout, const Bureaucrat &bureaucrat);

#endif