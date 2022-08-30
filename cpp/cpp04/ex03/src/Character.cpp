/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:02:31 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 19:10:59 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

// Constructors
Character::Character() {
    this->weaponCount = 0;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string name) {
    this->name = name;
    this->weaponCount = 0;
    std::cout << "Character constructor called" << std::endl;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    while (this->weaponCount > 0)
    {
        delete this->inventory[weaponCount - 1];
        weaponCount--;
    }
}

Character::Character(const Character & src) {
    this->weaponCount = src.weaponCount;
    for (int i = 0; i < (int)src.weaponCount; i++)
    {
        if (src.inventory[i]->getType() == "Ice")
        {
            Ice *   newIce = new Ice("Ice");
            this->inventory[i] = newIce;
        }
        else if (src.inventory[i]->getType() == "Cure")
        {
            Cure *   newCure = new Cure("Cure");
            this->inventory[i] = newCure;
        }

    }
    // TODO: copy inventory elements
    std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character &rhs) {
    this->weaponCount = rhs.weaponCount;
    // TODO: assign inventory elements (deep copies)
    std::cout << "Character copy assignment called" << std::endl;
    return (*this);
}

// Member functions
std::string const & Character::getName() const {
    return (this->name);
}

void Character::equip(AMateria* m) {
    
    if (this->weaponCount < 4)
    {
        inventory[weaponCount] = m;
        this->weaponCount++;
    }
}

void Character::unequip(int idx) {
    if (this->inventory[idx] != NULL )
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < (int)this->weaponCount)
        this->inventory[idx]->use(target);
}