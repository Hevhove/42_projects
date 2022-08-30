/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:53 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:38:19 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

//Constructors
WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal was constructed" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal was destructed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
    std::cout << "WrongAnimal was copied" << std::endl;
    (void)src;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & rhs) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}

// Member functions
void    WrongAnimal::makeSound(void) const {
    std::cout << "Some WrongAnimal sound..." << std::endl;
}

std::string     WrongAnimal::getType(void) const {
    return (type);
}