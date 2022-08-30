/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:53 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:38:19 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

//Constructors
Animal::Animal() {
    std::cout << "Animal was constructed" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal was destructed" << std::endl;
}

Animal::Animal(Animal const &src) {
    std::cout << "Animal was copied" << std::endl;
    (void)src;
}

Animal& Animal::operator=(Animal const & rhs) {
    std::cout << "Animal assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}

// Member functions
void    Animal::makeSound(void) const {
    std::cout << "Some animal sound..." << std::endl;
}

std::string     Animal::getType(void) const {
    return (type);
}