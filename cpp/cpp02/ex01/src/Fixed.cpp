/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:04 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/19 13:18:57 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() {
    this->_raw_bits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
    std::cout << "Int constructor called" << std::endl;
    this->_raw_bits = i<<FRAC_BITS;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    this->_raw_bits = roundf(f * (1 << this->FRAC_BITS));
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

float   Fixed::toFloat(void) const {
    return(this->_raw_bits / (float)(1 << this->FRAC_BITS));
}

int     Fixed::toInt(void) const {
    return (this->_raw_bits >> this->FRAC_BITS);
}


std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
    o << rhs.toFloat();
    return (o);
}