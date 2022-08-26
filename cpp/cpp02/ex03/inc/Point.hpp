/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:36:12 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/26 18:01:40 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_POINT_HPP
# define CLASS_POINT_HPP
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
    private:
        Fixed const x;
        Fixed const y;
        
    public:
        // Canonical Constructors
        Point();
        Point(Fixed const x, Fixed const y);
        Point(float const x, float const y);
        Point(Point const & src);
        ~Point();
        Point operator=(Point const &rhs);

        // Member functions
        float getX(void) const;
        float getY(void) const;
};

#endif