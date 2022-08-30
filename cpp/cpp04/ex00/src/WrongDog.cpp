/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:58 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:47:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongDog.hpp"

WrongDog::WrongDog() {
    std::cout << "WrongDog was constructed" << std::endl;
    this->WrongAnimal::type = "WrongDog"; 
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog was destructed" << std::endl;
}

WrongDog::WrongDog(WrongDog const &src) : WrongAnimal() {
    std::cout << "WrongDog was copied" << std::endl;
    (void)src;
}

WrongDog& WrongDog::operator=(WrongDog const & rhs) {
    std::cout << "WrongDog assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}

void    WrongDog::makeSound(void) const {
    std::cout << "Woof!" << std::endl;
}