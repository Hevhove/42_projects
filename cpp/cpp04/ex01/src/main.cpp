/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:52:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 12:35:18 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
    // Declare array
    const int   no_anim = 4;
    Animal*     animalArray[no_anim];
    
    // Creating animals
    std::cout << "[ CREATING OBJECTS ] " << std::endl;
    for (int i = 0; i < no_anim; i += 2)
    {
        animalArray[i] = new Cat();
        animalArray[i + 1] = new Dog();
    }
    
    // Testing Copies
    std::cout << std::endl << "[ TESTING COPY OBJECTS ] " << std::endl;
    Cat cat;
    Dog dog;

    Cat deepcat = cat;
    Dog deepdog = dog;

    std::cout << "address of kittybrain: " << cat.getBrainAddr() << std::endl;
    std::cout << "address of doggybrain: " << dog.getBrainAddr() << std::endl;
    std::cout << "address of deep kittybrain: " << deepcat.getBrainAddr() << std::endl;
    std::cout << "address of deep doggybrain: " << deepdog.getBrainAddr() << std::endl;
    
    // Destroying animals
    std::cout << std::endl << "[ DESTROYING OBJECTS ] " << std::endl;
    for (int i = 0; i < no_anim; i += 2)
    {
        delete animalArray[i];
        delete animalArray[i + 1];
    }
    return 0;
}

// int main(void)
// {
//     Animal  a;
//     Cat     kitty;
//     Dog     doggy;
    
//     a.makeSound();
//     kitty.makeSound();
//     doggy.makeSound();
    
//     std::cout << kitty.getType() << std::endl;
//     std::cout << doggy.getType() << std::endl;


//     return (0);
// }
