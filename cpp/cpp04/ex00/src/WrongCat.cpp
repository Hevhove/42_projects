/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:47:04 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat was constructed" << std::endl;
    this->WrongAnimal::type = "WrongCat"; 
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat was destructed" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal() {
    std::cout << "WrongCat was copied" << std::endl;
    (void)src;
}

WrongCat& WrongCat::operator=(WrongCat const & rhs) {
    std::cout << "WrongCat assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}

void    WrongCat::makeSound(void) const{
    std::cout << "Meow!" << std::endl;
}