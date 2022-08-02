/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:51:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/02 16:54:35 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# define MAX_CONTACTS 8
# include "Contact.hpp"

/*
    This class must be designed in the Orthodox Canonical Form:
        1. A default constructor -> a constructor with either no parameters or a constructor where all parameters have default values
        2. A copy constructor -> 
        3. A destructor
        4. Copy assignment operator
*/

class PhoneBook {
    private:
        Contact         contacts[MAX_CONTACTS];
        unsigned int    contacts_added;

    public:
        PhoneBook(); // constructor
        ~PhoneBook(); // destructor
        PhoneBook operator = (PhoneBook); // copy assignment
        void    add(void);
        void    search(void);
};

#endif