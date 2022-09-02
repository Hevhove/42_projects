/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:33:22 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/02 14:21:52 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ROBOTOMYREQUESTFORM_HPP
# define CLASS_ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <time.h>
# include <cstdlib>

class RobotomyRequestForm : public Form{
    private:
        std::string target;
                
    public:
        // Constructors
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm & src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm & rhs);

        // Member functions
        std::string getTarget(void);
        void        executeSpecForm() const;

        // Exceptions
        class RobotomyRequestFailureException : public std::exception {
            const char * what() const throw();
        };
};

#endif