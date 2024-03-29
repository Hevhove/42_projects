/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:04 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/19 11:38:14 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() {
    this->_raw_bits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
    this->_raw_bits = src._raw_bits;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src) {
    this->_raw_bits = src._raw_bits;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw_bits;
}

void    Fixed::setRawBits(int const raw) {
    this->_raw_bits = raw;
}
