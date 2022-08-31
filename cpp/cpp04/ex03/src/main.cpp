/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:22:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 13:59:50 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"

int main(void)
{
    Character       jerry("jerry");
    Character       bobby("bobby");
    Cure*           rodOfCuring = new Cure;
    Ice*            staffOfIce = new Ice;
    Cure*           swordOfHealing = new Cure;
    MateriaSource   sourceOfMateria;
    
    std::cout << "[EQUIP AND USE TEST]" << std::endl;
    // Jerry equips the rod of curing and heals bobby
    jerry.equip(rodOfCuring);
    jerry.use(0, bobby);
    jerry.equip(swordOfHealing);
    jerry.use(1, bobby);
    
    // Bobby equips the staffOfIce and attacks jerry
    bobby.equip(staffOfIce);
    bobby.use(0, jerry);

    // Copy a character over (deep copy proof)
    std::cout << "[ COPYING TEST ]" << std::endl;
    Character   alice(bobby);
    alice.use(0, bobby);
    std::cout << "address alice staff: " << alice.getInventoryItemAddress(0) << std::endl;
    std::cout << "address bobby staff: " << bobby.getInventoryItemAddress(0) << std::endl;
    
    // Clone method
    Ice*    clonedStaff = staffOfIce->clone();
    alice.equip(clonedStaff);
    alice.unequip(1);
    delete clonedStaff; // Otherwise memory leak!

    // MateriaSource
    sourceOfMateria.learnMateria(new Ice());
    sourceOfMateria.learnMateria(new Cure());

    // Space for destructors
    std::cout << "[ DESTRUCTORS ]" << std::endl;
    return (0);
}