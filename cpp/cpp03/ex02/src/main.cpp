/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:16:25 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:37 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main(void)
{
    ClapTrap trap1("Trappy the Trap", 10, 10, 2);
    ScavTrap scav1("Davy Crockett");
    FragTrap frag1("Zenedict Dumbercatch");

    // Trap 1 : Takes damage and dies
    trap1.attack("Pesky Rival");
    trap1.takeDamage(9);
    trap1.beRepaired(1);
    trap1.takeDamage(3);
    trap1.attack("Another Pesky Rival");

    // ScavTrap : 
    scav1.guardGate();

    // FragTrap : 
    frag1.highFivesGuys();
    return (0);
}