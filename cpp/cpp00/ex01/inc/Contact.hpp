/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:00:24 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/02 17:05:41 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact {
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string secret;

    public:
        Contact(); // constructor
        Contact(std::string, std::string, std::string, std::string, std::string);
        ~Contact(); // destructor
        Contact operator = (Contact); // copy assignment operator
        void    print_line();
        void    print();
        void    setFirstName(const std::string);
        void    setLastName(const std::string);
        void    setNickName(const std::string);
        void    setPhoneNumber(const std::string);
        void    setSecret(const std::string);
};

#endif