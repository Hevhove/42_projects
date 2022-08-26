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

// CANONICAL CONSTRUCTORS  
Fixed::Fixed() {
    this->_raw_bits = 0;
}

Fixed::Fixed(const int i) {
    this->_raw_bits = i<<FRAC_BITS;
}

Fixed::Fixed(const float f) {
    this->_raw_bits = roundf(f * (1 << this->FRAC_BITS));
}

Fixed::Fixed(Fixed const & src) {
    this->_raw_bits = src._raw_bits;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& src) {
    this->_raw_bits = src._raw_bits;
    return *this;
}

// OPERATOR OVERLOADS
bool Fixed::operator>(Fixed const & rhs) const {
    if ((this->_raw_bits << 8) == (rhs._raw_bits << 8))
    {
        if ((this->_raw_bits & 0xFF) > (rhs._raw_bits & 0xFF))
            return (true);
        else
            return (false);
    }
    else if ((this->_raw_bits << 8) > (rhs._raw_bits << 8))
        return (true);
    return (false);
}

bool Fixed::operator<(Fixed const &rhs) const {
    if ((this->_raw_bits << 8) == (rhs._raw_bits << 8))
    {
        if ((this->_raw_bits & 0xFF) < (rhs._raw_bits & 0xFF))
            return (true);
        else
            return (false);
    }
    else if ((this->_raw_bits << 8) < (rhs._raw_bits << 8))
        return (true);
    return (false);    
}

bool Fixed::operator>=(Fixed const &rhs) const {
    if ((this->_raw_bits << 8) == (rhs._raw_bits << 8))
    {
        if ((this->_raw_bits & 0xFF) >= (rhs._raw_bits & 0xFF))
            return (true);
        else
            return (false);
    }
    else if ((this->_raw_bits << 8) >= (rhs._raw_bits << 8))
        return (true);
    return (false);    
}

bool Fixed::operator<=(Fixed const &rhs) const {
    if ((this->_raw_bits << 8) == (rhs._raw_bits << 8))
    {
        if ((this->_raw_bits & 0xFF) <= (rhs._raw_bits & 0xFF))
            return (true);
        else
            return (false);
    }
    else if ((this->_raw_bits << 8) <= (rhs._raw_bits << 8))
        return (true);
    return (false);    
}

bool Fixed::operator==(Fixed const &rhs) const {
    if ((this->_raw_bits << 8) == (rhs._raw_bits << 8))
    {
        if ((this->_raw_bits & 0xFF) == (rhs._raw_bits & 0xFF))
            return (true);
        else
            return (false);
    }
    else if ((this->_raw_bits << 8) == (rhs._raw_bits << 8))
        return (true);
    return (false);    
}

bool Fixed::operator!=(Fixed const &rhs) const {
    if ((this->_raw_bits << 8) == (rhs._raw_bits << 8))
    {
        if ((this->_raw_bits & 0xFF) != (rhs._raw_bits & 0xFF))
            return (true);
        else
            return (false);
    }
    else if ((this->_raw_bits << 8) != (rhs._raw_bits << 8))
        return (true);
    return (false);    
}

Fixed Fixed::operator+(Fixed const & rhs) const {
    return (Fixed((this->toFloat() + rhs.toFloat())));
}

Fixed Fixed::operator-(Fixed const & rhs) const {
    return (Fixed((this->toFloat() - rhs.toFloat())));
}

Fixed Fixed::operator*(Fixed const & rhs) const {
    return (Fixed((this->toFloat() * rhs.toFloat())));
}

Fixed Fixed::operator/(Fixed const & rhs) const {
    return (Fixed((this->toFloat() / rhs.toFloat())));
}

Fixed Fixed::operator++(){
    ++this->_raw_bits;
    return (*this);
}

Fixed Fixed::operator--(){
    --this->_raw_bits;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed tmp = *this;
    this->_raw_bits++;
    return (tmp);
}

Fixed Fixed::operator--(int){
    Fixed tmp = *this;
    this->_raw_bits--;
    return (tmp);
}

// MEMBER FUNCTIONS
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

// STATIC MEMBER FUNCTIONS
Fixed & Fixed::min(Fixed & lhs, Fixed & rhs) {
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

const Fixed & Fixed::min(Fixed const & lhs, Fixed const & rhs) {
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs) {
    if (lhs > rhs)
        return (lhs);
    return (rhs);
}

const Fixed & Fixed::max(Fixed const & lhs, Fixed const & rhs) {
    if (lhs > rhs)
        return (lhs);
    return (rhs);
}

// NON-MEMBER FUNCTIONS
std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
    o << rhs.toFloat();
    return (o);
}