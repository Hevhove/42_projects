/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:58 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 12:41:31 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
    this->Animal::type = "Dog";
    this->doggybrain = new Brain();
    std::cout << "Dog was constructed" << std::endl;
}

Dog::~Dog() {
    delete this->doggybrain;
    std::cout << "Dog was destructed" << std::endl;
}

Dog::Dog(Dog const &src) : Animal() {
    this->type = src.type;
    this->doggybrain = new Brain(*src.doggybrain);
    std::cout << "Dog was copied" << std::endl;
}

Dog& Dog::operator=(Dog const & rhs) {
    this->type = rhs.type;
    this->doggybrain = new Brain(*rhs.doggybrain);
    std::cout << "Dog assignment operator called" << std::endl;;
    return (*this);
}

void    Dog::makeSound(void) const{
    std::cout << "Woof!" << std::endl;
}

Brain*    Dog::getBrainAddr(void) const {
    return (this->doggybrain);
}