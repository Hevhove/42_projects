/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:02 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/26 16:38:22 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FIXED_HPP
# define CLASS_FIXED_HPP
# include <iostream>
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int                 _raw_bits;
        static const int    FRAC_BITS = 8;
        
    public:
        // Canonical Constructors
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        Fixed(Fixed const & src);
        ~Fixed();
        Fixed& operator=(Fixed const & rhs);

        // Member functions
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif