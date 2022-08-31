/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:02:31 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 13:52:56 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    weaponCount = 0;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = 0;
    std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < weaponCount; i++)
    {
    if (inventory[i])
        delete  inventory[i];
    }
    std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    inventory[weaponCount++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < weaponCount; i++)
    {
        if (inventory[i] && inventory[i]->getType() == type)
            return  inventory[i]->clone();
    }
    return (NULL);
}