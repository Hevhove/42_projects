/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 12:49:55 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() {
    this->AAnimal::type = "Cat";
    this->kittybrain = new Brain();
    std::cout << "Cat was constructed" << std::endl;
}

Cat::~Cat() {
    delete this->kittybrain;
    std::cout << "Cat was destructed" << std::endl;
}

Cat::Cat(Cat const &src) : AAnimal() {
    this->type = src.type;
    this->kittybrain = new Brain(*src.kittybrain);
    std::cout << "Cat was copied" << std::endl;
}

Cat& Cat::operator=(Cat const & rhs) {
    this->type = rhs.type;
    this->kittybrain = new Brain(*rhs.kittybrain);
    std::cout << "Cat assignment operator called" << std::endl;;
    return (*this);
}

void    Cat::makeSound(void) const{
    std::cout << "Meow!" << std::endl;
}

Brain*    Cat::getBrainAddr(void) const {
    return (this->kittybrain);
}