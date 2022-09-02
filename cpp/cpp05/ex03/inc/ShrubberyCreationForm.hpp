/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:27:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:21:48 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SHRUBBERYCREATIONFORM_HPP
# define CLASS_SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {
    private:
        std::string target;
        
    public:
        // Constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm & rhs);

        // Member functions
        std::string getTarget(void);
        void        executeSpecForm() const;

        // Exceptions
        class ShrubberyCreationFailureException : public std::exception {
            const char * what() const throw();
        };
};

#endif