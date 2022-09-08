/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:56:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/08 13:15:23 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

int main(void)
{
    Base* obj1;
    Base* obj2;
    Base* obj3;

    // Generate random objects
    srand(time(NULL));
    obj1 = generate();
    obj2 = generate();
    obj3 = generate();

    // Identify by pointer;
    std::cout << "Pointer identification: " << std::endl;
    identify(obj1);
    identify(obj2);
    identify(obj3);

    // Identify by reference;
    std::cout << "Reference identification: " << std::endl;
    identify(*obj1);
    identify(*obj2);
    identify(*obj3);

    delete obj1;
    delete obj2;
    delete obj3;
    
    return (0);
}