/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:44:06 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/07 19:04:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONVERSION_HPP
# define CLASS_CONVERSION_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <climits>
# include <limits>
# include <sstream>
# define NB_TYPE_CONVERSIONS 4

class Conversion {
    private:
        // Typedefs
        typedef enum e_status
        {
            NOT_CONVERTED,
            IMPOSSIBLE,
            NON_DISPLAYABLE,
            CONVERTED
        }   t_status;

        typedef enum e_types
        {
            T_CHAR,
            T_INT,
            T_DOUBLE,
            T_FLOAT,
            T_NONE
        }   t_types;

        typedef struct s_conversion_table
        {
            t_status    status;
            void        (Conversion::*conversionFunction)(const std::string&);
        }   t_conversion_table;

        typedef struct s_conversion
        {
            char    c;
            int     i;
            float   f;
            double  d;
        }   t_conversion;

        // Variables
        t_conversion_table  conversion_table[NB_TYPE_CONVERSIONS + 1];
        t_conversion        converted;

        // Type Detection
        t_types     getType(const std::string& input);
        bool        isChar(const std::string& input);
        bool        isInt(const std::string& input);
        bool        isFloat(const std::string& input);
        bool        isDouble(const std::string& input);

        // Limits checks for conversions
        t_status    setCharStatus(const char &c);
        std::string convertToString(int i);
        float       setFloat(const std::string &str);
        double      setDouble(const std::string &str);

        // Conversion functions
        void        convertToChar(const std::string &str);
        void        convertToInt(const std::string &str);
        void        convertToFloat(const std::string &str);
        void        convertToDouble(const std::string &str);
        void        allImpossible(const std::string &str);

        // Printing errors
        bool        printError(int status) const;

    public:
        // Constructors
        Conversion();
        Conversion(std::string input);
        ~Conversion();
        Conversion(const Conversion & src);
        Conversion& operator=(Conversion const & rhs);

        // Printing
        void    print() const;
};

#endif