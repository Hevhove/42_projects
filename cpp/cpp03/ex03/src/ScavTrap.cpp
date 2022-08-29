/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:35:10 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 17:10:20 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
    
ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Constructor has been called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap " << name << " was initialized by constructor!" << std::endl;
    this->name = name;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.name) {
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor has been called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
    this->name = rhs.name;
    this->hp = rhs.hp;
    this->ep = rhs.ep;
    this->ad = rhs.ad;
    return *this;
}

void            ScavTrap::attack(const std::string& target) {
    if (this->ep > 0 && this->hp > 0)
    {
        this->ep--;
        std::cout << "ScavTrap " << this->name << "  attacks " << target << " for " << this->ad << " attack damage" << std::endl; 
    }
    else if (this->hp <= 0)
    {
        std::cout << "ScavTrap " << this->name << "  is dead and cannot attack!" << std::endl;
    }
    else if (this->ep <= 0)
    {
        std::cout << "ScavTrap " << this->name << "  is out of energy and cannot attack!" << std::endl;
    }
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode!" << std::endl;
}