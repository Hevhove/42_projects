/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:55:14 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:20 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() {
    std::cout << "ClapTrap Constructor has been called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap Constructor has been called!" << std::endl;
    this->name = name;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) {
    this->name = name;
    this->hp = hp;
    this->ep = ep;
    this->ad = ad;
    std::cout << "ClapTrap Constructor has been called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor has been called!" << std::endl;;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & src) {
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;
    return *this;
}

// Member functions
void            ClapTrap::attack(const std::string& target) {
    if (this->ep > 0 && this->hp > 0)
    {
        this->ep--;
        std::cout << "ClapTrap " << this->name << "  attacks " << target << " for " << this->ad << " attack damage" << std::endl; 
    }
    else if (this->hp <= 0)
    {
        std::cout << "ClapTrap " << this->name << "  is dead and cannot attack!" << std::endl;
    }
    else if (this->ep <= 0)
    {
        std::cout << "ClapTrap " << this->name << "  is out of energy and cannot attack!" << std::endl;
    }
}
void            ClapTrap::takeDamage(unsigned int amount) {
    if (this->hp > 0)
    {
        if (this->hp > amount)
        {
            this->hp -= amount;
        }
        else
            this->hp = 0;
        std::cout << "ClapTrap " << this->name << "  has taken " << amount << " damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << "  is already dead!" << std::endl;
    }
    
}

void            ClapTrap::beRepaired(unsigned int amount) {
    if (this->ep > 0 && this->hp > 0)
    {
        this->ep--;
        this->hp += amount;
        std::cout << "ClapTrap " << this->name << " has been repaired for " << amount << " hitpoints!" << std::endl;
    }
    else if (this->hp <= 0)
    {
        std::cout << "ClapTrap " << this->name << "  is dead and cannot repair itself!" << std::endl;
    }
    else if (this->ep <= 0)
    {
        std::cout << "ClapTrap " << this->name << "  does not have the energy to repair itself!" << std::endl;
    }
    
}