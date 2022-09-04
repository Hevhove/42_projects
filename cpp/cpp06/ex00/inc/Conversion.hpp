/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:26:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/09/04 17:35:36 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONVERSION_CPP
# define CLASS_CONVERSION_CPP
# include <iostream>
# include <string>

class Conversion {
	private:
		char	char_val;
		int		int_val;
		float	float_val;
		double	double_val;

		// Conversion functions
		char	toChar(const char *);
		int		toInt(const char *);
		float	toFloat(const char *);
		double	toDouble(const char *);



	public:
		// Constructors
		Conversion();
		Conversion(const char *);
		~Conversion();
		Conversion(const Conversion & src);
		Conversion& operator=(const Conversion &rhs);

		// Member functions
};

#endif
