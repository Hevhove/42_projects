/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:04 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/18 19:56:16 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() {
    this->_raw_bits = 0;
}

Fixed::Fixed(Fixed const & src) {
    this->_raw_bits = src._raw_bits;
}

Fixed::~Fixed() {
    ;
}

Fixed& Fixed::operator=(const Fixed& copy) {
    ;
}

int     Fixed::getRawBits(void) const {
    return this->_raw_bits;
}

void    Fixed::setRawBits(int const raw) {
    this->_raw_bits = raw;
}
