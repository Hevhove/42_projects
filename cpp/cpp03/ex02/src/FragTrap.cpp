/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:26:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:26 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap Constructor has been called!" << std::endl;;
}

FragTrap::FragTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) {
    std::cout << "FragTrap " << name << " was initialized by constructor!" << std::endl;
    this->name = name;
    this->hp = hp;
    this->ep = ep;
    this->ad = ad;
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

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " is asking for a high-five!" << std::endl;
}