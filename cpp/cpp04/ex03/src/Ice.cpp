/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:59:17 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 18:55:02 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() {
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(std::string type) {
    this->type = type;
    std::cout << "Ice parametrical constructor called" << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice & src) : AMateria() {
    this->type = src.type;
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &rhs) {
    this->type = rhs.type;
    std::cout << "Ice copy assignment called" << std::endl;
    return (*this);
}

void    Ice::use(ICharacter& target) {
    std::cout << "* shoots an icebolt at " << target.getName() << std::endl;
}

AMateria* Ice::clone(void) const { 
    return (new Ice(type));
}