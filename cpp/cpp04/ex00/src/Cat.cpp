/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 11:16:33 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() {
    std::cout << "Cat was constructed" << std::endl;
    this->Animal::type = "Cat"; 
}

Cat::~Cat() {
    std::cout << "Cat was destructed" << std::endl;
}

Cat::Cat(Cat const &src) : Animal() {
    std::cout << "Cat was copied" << std::endl;
    (void)src;
}

Cat& Cat::operator=(Cat const & rhs) {
    std::cout << "Cat assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}

void    Cat::makeSound(void) const{
    std::cout << "Meow!" << std::endl;
}