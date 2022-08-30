/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:53 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:38:19 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

//Constructors
AAnimal::AAnimal() {
    std::cout << "AAnimal was constructed" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal was destructed" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
    std::cout << "AAnimal was copied" << std::endl;
    (void)src;
}

AAnimal& AAnimal::operator=(AAnimal const & rhs) {
    std::cout << "AAnimal assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}

// Member functions
void    AAnimal::makeSound(void) const {
    std::cout << "Some AAnimal sound..." << std::endl;
}

std::string     AAnimal::getType(void) const {
    return (type);
}