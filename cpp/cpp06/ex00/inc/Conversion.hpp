/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:26:08 by Hendrik           #+#    #+#             */
/*   Updated: 2022/09/06 14:43:47 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONVERSION_CPP
# define CLASS_CONVERSION_CPP
# include <iostream>
# include <string>
# include <cmath>
# include <climits>
# include <cfloat>

class Conversion {
	private:
		// input string
		std::string str;
		
		// status check
		bool	isConverted;

		// Converted values
		char	c;
		int		i;
		float	f;
		double	d;

		// Helper values for ranges
		long int	li;
		long double	ld;

		// Type detection
		typedef enum Types {CHAR, INT, FLOAT, DOUBLE, NONE} type_t; 
		type_t	typeDetect(std::string str);
		
		bool	isChar(std::string str);
		bool	isInt(std::string str);
		bool	isFloat(std::string str);
		bool	isDouble(std::string str);

		// Conversion functions
		void	executeConversions(type_t type);
		
		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
		void	toLongDouble();
		
		void	charConversions();
		void	intConversions();
		void	floatConversions();
		void	doubleConversions();

		// Range checking
		bool	intOutOfRange();
		bool	floatOutOfRange();
		bool	doubleOutOfRange();

	public:
		// Constructors
		Conversion();
		Conversion(const char *);
		~Conversion();
		Conversion(const Conversion & src);
		Conversion& operator=(const Conversion &rhs);

		// Printing functions
		void	printConversions(void) const;
};

#endif
