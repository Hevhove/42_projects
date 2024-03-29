/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:02 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/26 16:37:00 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FIXED_HPP
# define CLASS_FIXED_HPP
# include <iostream>

class Fixed {
    private:
        int                 _raw_bits;
        static const int    FRAC_BITS = 8;
        
    public:
        // Canonical Constructors
        Fixed();
        Fixed(Fixed const & src);
        ~Fixed();
        Fixed& operator=(Fixed const & rhs);

        // Member functions
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif