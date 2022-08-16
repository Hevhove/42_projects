/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:30:10 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/16 17:49:12 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weap) : _name(name), _weapon(weap){
    //
}

HumanA::~HumanA() {
    //
}

void    HumanA::attack(void) {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}