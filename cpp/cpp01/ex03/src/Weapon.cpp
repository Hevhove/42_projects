/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:39:03 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/16 17:01:19 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon() {
    // 
}

Weapon::Weapon(std::string type) : _type(type) {
    // 
}

Weapon::~Weapon() {
    // 
}

const std::string&  Weapon::getType(void) const {
    return (this->_type);
}

void                Weapon::setType(std::string type) {
    this->_type = type;
}