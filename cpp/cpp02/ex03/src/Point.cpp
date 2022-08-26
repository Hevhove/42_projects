/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:52:05 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/26 18:02:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point(void) : x(Fixed(0)), y(Fixed(0)) {

}

Point::Point(Fixed const x, Fixed const y) : x(Fixed(x)), y(Fixed(y)) {

}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y)) {

}

Point::Point(Point const &src) : x(src.x), y(src.y) {
    
}

Point::~Point(void) {
    
}

Point  Point::operator=(Point const &rhs) {
    Point tmp(rhs);
    return tmp;
}

float   Point::getX(void) const {
    return ((this->x).toFloat());
}

float   Point::getY(void) const {
    return ((this->y).toFloat());
}