/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:22:27 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 18:54:02 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Character.hpp"

int main(void)
{
    Character   jerry("jerry");
    Character   bobby("bobby");
    Cure*        rodOfCuring = new Cure;
    Ice*         staffOfIce = new Ice;
    
    // Jerry equips the rod of curing and heals bobby
    jerry.equip(rodOfCuring);
    jerry.use(0, bobby);
    std::cout << std::endl;
    
    // Bobby equips the staffOfIce and attacks jerry
    bobby.equip(staffOfIce);
    bobby.use(0, jerry);
    std::cout << std::endl;

    // Copy a character over
    Character   alice(bobby);
    alice.use(0, bobby);
    return (0);
}