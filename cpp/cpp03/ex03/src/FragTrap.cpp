/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:26:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 17:10:05 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/FragTrap.hpp>

FragTrap::FragTrap() {
    std::cout << "FragTrap Constructor has been called!" << std::endl;;
    this->name = "";
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
}

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTrap " << name << " was initialized by constructor!" << std::endl;
    this->name = name;
    this->hp = 100;
    this->ep = 100;
    this->ad = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src.name) {
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor has been called!" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs) {
    this->name = rhs.name;
    this->hp = rhs.hp;
    this->ep = rhs.ep;
    this->ad = rhs.ad;
    return *this;
}

void            FragTrap::attack(const std::string& target) {
    if (this->ep > 0 && this->hp > 0)
    {
        this->ep--;
        std::cout << "FragTrap " << this->name << "  attacks " << target << " for " << this->ad << " attack damage" << std::endl; 
    }
    else if (this->hp <= 0)
    {
        std::cout << "FragTrap " << this->name << "  is dead and cannot attack!" << std::endl;
    }
    else if (this->ep <= 0)
    {
        std::cout << "FragTrap " << this->name << "  is out of energy and cannot attack!" << std::endl;
    }
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " is asking for a high-five!" << std::endl;
}