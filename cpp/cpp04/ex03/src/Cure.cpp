/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:51:10 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 18:04:53 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() {
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(std::string type) {
    this->type = type;
    std::cout << "Cure parametrical constructor called" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure & src) : AMateria() {
    this->type = src.type;
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &rhs) {
    this->type = rhs.type;
    std::cout << "Cure copy assignment called" << std::endl;
    return (*this);
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone(void) const { 
    return (new Cure(type));
}