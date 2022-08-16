/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:39:58 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/16 17:08:18 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    //
}

HumanB::~HumanB() {
    //
}

void    HumanB::setWeapon(Weapon& weap) {
    this->_weapon = &weap;
}

void    HumanB::attack(void) {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}