/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:00:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 17:09:45 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    this->name = "NULL";
    ClapTrap::name =  (this->name + "_clap_name");
    std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
    this->hp    = FragTrap::hp;
    this->ep    = ScavTrap::ep;
    this->ad    = FragTrap::ad;
    this->name  = name;
    ClapTrap::name =  (this->name + "_clap_name");
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src.name), FragTrap(src.name), ScavTrap(src.name) {
   *this = src;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Diamond destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
    this->name = rhs.name;
    this->ClapTrap::name = rhs.ClapTrap::name;
    this->hp = rhs.hp;
    this->ep = rhs.ep;
    this->ad = rhs.ad;
    return (*this);
}

void    DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) {
    std::cout << "My ClapTrap Name is: " << ClapTrap::name << std::endl;
    std::cout << "My DiamondTrap Name is: " << DiamondTrap::name << std::endl;
}