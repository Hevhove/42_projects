/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:06:41 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/05 13:32:53 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include "../inc/myawesomephonebook.hpp"

class Contact {
    private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkSecret;

    public:
		Contact();
        ~Contact();
		void		setFirstName();
		void		setLastName(void);
		void		setNickName(void);
		void		setPhoneNumber(void);
		void		setDarkSecret(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkSecret(void);
		std::string	formatContact(std::string);
};

#endif
