/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:49:25 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/28 17:52:23 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap Constructor has been called!" << std::endl;;
}

DiamondTrap::DiamondTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) {
    std::cout << "DiamondTrap " << name << " was initialized by constructor!" << std::endl;
    this->name = name;
    this->hp = hp;
    this->ep = ep;
    this->ad = ad;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src.name) {
    this->name = src.name;
    this->hp = src.hp;
    this->ep = src.ep;
    this->ad = src.ad;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor has been called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs) {
    this->name = rhs.name;
    this->hp = rhs.hp;
    this->ep = rhs.ep;
    this->ad = rhs.ad;
    return *this;
}

void    DiamondTrap::DiamondTrap(void) {
    std::cout << "My name is: " << DiamondTrap::name << " and my ClapTrap name is : " << ClapTrap::name << std::endl; 
}