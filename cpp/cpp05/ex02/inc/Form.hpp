/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:25:50 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:23:22 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_Form_HPP
# define CLASS_Form_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string   name;
        bool                signedStatus;
        const int           signingGradeRequired;
        const int           executingGradeRequired;
    
    public:
        // Constructors
        Form();
        Form(std::string name);
        Form(std::string name, const int signingGradeRequired, const int executingGradeRequired);
        ~Form();
        Form(Form const & src);
        Form& operator=(Form const & rhs);
        
        // Member functions
        const std::string   getName(void) const;
        bool                getSignedStatus(void) const;
        int                 getSigningGradeRequired(void) const;
        int                 getExecutingGradeRequired(void) const;
        void                beSigned(const Bureaucrat & bur);
        // New for Ex02
        void                execute(const Bureaucrat & executor) const;
        virtual void        executeSpecForm() const = 0;

        // Exceptions
        class GradeTooLowException : public std::exception {
            const char * what () const throw ();
        };

        class GradeTooHighException : public std::exception {
            const char * what () const throw ();
        };

        class SigningGradeTooLowException : public std::exception {
            const char * what () const throw ();
        };

        class AlreadySignedException : public std::exception {
            const char * what () const throw ();
        };

        class ExecuteFailureExeption : public std::exception {
            const char * what () const throw ();
        };
};

std::ostream & operator<<(std::ostream &stdout, const Form &Form);

#endif