/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:32:13 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 11:44:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
    this->type = type;
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria & src) {
    this->type = src.type;
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &rhs) {
    this->type = rhs.type;
    std::cout << "AMateria copy assignment called" << std::endl;
    return (*this);
}

void    AMateria::use(ICharacter& target) {
    std::cout << "No Materia specified to use against " << target.getName() << std::endl;
}

std::string const & AMateria::getType(void) const {
    return this->type;
}