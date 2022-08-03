/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:09:40 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/03 12:38:26 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# define MAX_CONTACTS 8
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <limits>

class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        int     index;
        int     numContacts;
        
    public:
        // Constructors
        PhoneBook();
        ~PhoneBook();
        // Member functions
        void    addContact();
        void    displayContacts();
        void    displayInfo(int index);
};

#endif