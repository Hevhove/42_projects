/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:12:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/02 17:00:34 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myawesomephonebook.hpp"
#include "../inc/Contact.hpp"

Contact::Contact(){ }; // constructor does nothing

Contact::~Contact(){ }; // constructor does nothing

void Contact::setFirstName(const std::string fn){
    this->firstname = fn;
}

void Contact::setLastName(const std::string ln){
    this->lastname = ln;
}

void Contact::setNickName(const std::string nn){
    this->nickname = nn;
}

void Contact::setPhoneNumber(const std::string pn){
    this->phonenumber = pn;
}

void Contact::setSecret(const std::string s){
    this->secret = s;
}