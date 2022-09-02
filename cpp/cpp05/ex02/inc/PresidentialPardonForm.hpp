/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:09:22 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:22:10 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PRESIDENTIALPARDONFORM_HPP
# define CLASS_PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form{
    private:
        std::string target;
        
    public:
        // Constructors
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm & src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm & rhs);

        // Member functions
        std::string getTarget(void);
        void        executeSpecForm() const; 
                
        // Exceptions
        class PresidentialPardonFailureException : public std::exception {
            const char * what() const throw();
        };
};

#endif