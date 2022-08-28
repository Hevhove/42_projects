/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:35:10 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/28 16:12:25 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
    
ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Constructor has been called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) {
    std::cout << "ScavTrap " << name << " was initialized by constructor!" << std::endl;
    this->name = name;
    this->hp = hp;
    this->ep = ep;
    this->ad = ad;
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

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode!" << std::endl;
}