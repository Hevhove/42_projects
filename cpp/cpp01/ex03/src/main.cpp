/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:18:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/16 17:48:26 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int main(void)
{
    /*
        In HumanA, we have a REFERENCE to the Weapon club. Without the reference, 
        below code would not succeed in changing the weapon contained inside of object HumanA,
        because HumanA's weapon is a copy in a different memory address and is initialized
        with the copy constuctor of the Weapon Class.
    */
    {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    /*
        In this example we have to use a pointer and not a reference, because it 
        is possible for the human to have no weapon. A reference can NEVER be NULL
    */
    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }
}