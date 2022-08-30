/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:58 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 11:16:40 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
    std::cout << "Dog was constructed" << std::endl;
    this->Animal::type = "Dog"; 
}

Dog::~Dog() {
    std::cout << "Dog was destructed" << std::endl;
}

Dog::Dog(Dog const &src) : Animal() {
    std::cout << "Dog was copied" << std::endl;
    (void)src;
}

Dog& Dog::operator=(Dog const & rhs) {
    std::cout << "Dog assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}

void    Dog::makeSound(void) const{
    std::cout << "Woof!" << std::endl;
}