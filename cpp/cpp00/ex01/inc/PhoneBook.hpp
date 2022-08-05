/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:09:40 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/05 13:32:43 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# define MAX_CONTACTS 8
# include "../inc/myawesomephonebook.hpp"


class PhoneBook {
    private:
        Contact contacts[MAX_CONTACTS];
        int     index;
        int     numContacts;

    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    displayContacts();
        void    displayInfo(int index);
};

#endif
