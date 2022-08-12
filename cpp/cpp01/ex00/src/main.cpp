/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:03:03 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/12 17:16:52 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/Zombie.hpp>

int main(void)
{
    Zombie *zombie;

    randomChump("Chumpie");
    zombie = newZombie("Jack");
    zombie->announce();
    delete zombie;
}