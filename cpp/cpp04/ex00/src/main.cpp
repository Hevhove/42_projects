/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:52:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 11:11:47 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongDog.hpp"
#include "../inc/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl << "TESTS WITH WRONGCAT / WRONGDOG / WRONGANIMAL" << std::endl;
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* j2 = new WrongDog();
    const WrongAnimal* i2 = new WrongCat();
    
    std::cout << j2->getType() << " " << std::endl;
    std::cout << i2->getType() << " " << std::endl;
    
    i2->makeSound();
    j2->makeSound();
    meta2->makeSound();
    
    return (0);
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
