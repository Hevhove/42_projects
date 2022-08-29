/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:16:25 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:35 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main(void)
{
    ClapTrap trap1("Trappy the Trap", 10, 10, 2);
    ClapTrap trap2("Davy Crockett", 5, 5, 1);
    
    // Trap 1 : Takes damage and dies
    trap1.attack("Pesky Rival");
    trap1.takeDamage(9);
    trap1.beRepaired(1);
    trap1.takeDamage(3);
    trap1.attack("Another Pesky Rival");

    // Trap 2 : Attacks a lot and runs out of energy
    for (unsigned int i = 0; i < 8; i++)
        trap2.attack("bear");
    trap2.beRepaired(2);
    return (0);
}