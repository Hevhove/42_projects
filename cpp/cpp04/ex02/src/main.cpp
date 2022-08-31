/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:52:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 12:25:35 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
    // THIS WILL NOT WORK BECAUSE ANIMAL IS NOW ABSTRACT
    // AAnimal animal1;
    
    // Declare array
    const int   no_anim = 4;
    AAnimal*     AnimalArray[no_anim];
    
    // Creating AAnimals
    std::cout << "[ CREATING OBJECTS ] " << std::endl;
    for (int i = 0; i < no_anim; i += 2)
    {
        AnimalArray[i] = new Cat();
        AnimalArray[i + 1] = new Dog();
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
    
    // Destroying AAnimals
    std::cout << std::endl << "[ DESTROYING OBJECTS ] " << std::endl;
    for (int i = 0; i < no_anim; i += 2)
    {
        delete AnimalArray[i];
        delete AnimalArray[i + 1];
    }
    return 0;
}

// int main(void)
// {
//     AAnimal  a;
//     Cat     kitty;
//     Dog     doggy;
    
//     a.makeSound();
//     kitty.makeSound();
//     doggy.makeSound();
    
//     std::cout << kitty.getType() << std::endl;
//     std::cout << doggy.getType() << std::endl;


//     return (0);
// }
