/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:28:25 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/06 15:00:12 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Conversion.hpp"

// Constructors
Conversion::Conversion(const char *s) : str(s), isConverted(false), c(0), i(0), f(0.0f), d(0.0), ld(0.0) {
    // Step 1: detect the type of literal passed as a parameter
    // Char:    value between 32 and 126 of length 1
    // Int:     string of numbers without decimal
    // Float:   string of numbers with decimal and ending in f
    // Double:  string of numbers with decimal
    type_t type = typeDetect(str);
    executeConversions(type);
}

Conversion::~Conversion()
{
    
}

// Conversions
void    Conversion::executeConversions(type_t type) {
    switch (type)
    {
        case (CHAR):
            toChar();
            charConversions();
            break;
        case (INT):
            toLongDouble();
            toInt();
            intConversions();
            break;
        case (FLOAT):
            toFloat();
            floatConversions();            
            break;
        case (DOUBLE):
            toDouble();
            doubleConversions();
            break ;
        case (NONE):
            this->isConverted = false;
            break;
    }
}

void    Conversion::toLongDouble(void) {
    int minus = (str[0] == '-') ? -1 : 1;
    int minus_check = (minus == -1) ? 1 : 0;
    int predecimal_count = str.find(".");
    int dot = 0;
    
    for (std::string::size_type i = minus_check; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            dot = 1;
            continue ;
        }
        this->ld += (static_cast<long double>((this->str)[i]) - 48) * static_cast<long double>(pow(10, predecimal_count - (int)i + dot - 1));
    }
    this->ld *= minus;
    std::cout << "LONG DOUBLE IS: " << this->ld << std::endl;
}

void    Conversion::toChar(void) {
    this->c = (this->str)[0];
}

void    Conversion::toInt(void) {
    int minus = (str[0] == '-') ? -1 : 1;

    if (minus == -1)
    {
        for (std::string::size_type i = 1; i < str.size(); i++)
            this->i += (static_cast<int>((this->str)[i]) - 48) * pow(10, str.size() - i - 1);
        this->i *= minus;
        return ;
    }
    for (std::string::size_type i = 0; i < str.size(); i++)
        this->i += (static_cast<int>((this->str)[i]) - 48) * pow(10, str.size() - i - 1);
    this->i *= minus;
}

void    Conversion::toFloat(void) {
    int minus = (str[0] == '-') ? -1 : 1;
    int minus_check = (minus == -1) ? 1 : 0;
    int predecimal_count = str.find(".");
    int dot = 0;

    for (std::string::size_type i = minus_check; i < str.size() - 1; i++)
    {
        if (str[i] == '.')
        {
            dot = 1;
            continue ;
        }
        this->f += (static_cast<float>((this->str)[i]) - 48) * pow(10, predecimal_count - (int)i + dot - 1);
    }
    this->f *= minus;
}

void	Conversion::toDouble(void) {
    int minus = (str[0] == '-') ? -1 : 1;
    int minus_check = (minus == -1) ? 1 : 0;
    int predecimal_count = str.find(".");
    int dot = 0;
    
    for (std::string::size_type i = minus_check; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            dot = 1;
            continue ;
        }
        this->d += (static_cast<double>(((this->str)[i]) - 48) * pow(10, predecimal_count - (int)i + dot - 1));
    }
    this->d *= minus;
}

void    Conversion::charConversions(void) {
    this->i = static_cast<int>(this->c);
    this->f = static_cast<float>(this->c);
    this->d = static_cast<double>(this->c);
    this->isConverted = true;
}

void    Conversion::intConversions(void) {
    this->c = static_cast<char>(this->i);
    this->f = static_cast<float>(this->i);
    this->d = static_cast<double>(this->i);
    this->isConverted = true;
}

void    Conversion::floatConversions(void) {
    this->c = static_cast<char>(this->f);
    this->i = static_cast<int>(this->f);
    this->d = static_cast<double>(this->f);
    this->isConverted = true;
}

void    Conversion::doubleConversions(void) {
    this->c = static_cast<char>(this->d);
    this->i = static_cast<int>(this->d);
    this->f = static_cast<float>(this->d);
    this->isConverted = true;
}

// Type Detection
Conversion::type_t     Conversion::typeDetect(std::string str) {
    if (isChar(str))
        return (CHAR);
    else if (isInt(str))
         return (INT);
    else if (isFloat(str))
    {
        return (FLOAT);
    }
    else if (isDouble(str))
        return (DOUBLE);
    else 
        return (NONE);
}

bool    Conversion::isChar(std::string str) {
    /*
        We have a character if the string is:
            1. Length = 1
            2. Between range 0 and 127 (CHAR Range)
            3. We handle displayability later
    */
    if (str.length() == 1 && (str[0] < 48 || str[0] > 57))
    {
        return (true);
    }
    else
        return (false);
}

bool    Conversion::isInt(std::string str) {
    /*
        We have an int if the string is:
            1. a sequence of all numbers
            2. Can be prefixed by a minus
    */
    for (std::string::size_type i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 48 && str[i] <= 57))
            continue ;
        else if (i == 0 && str[i] == '-')
            continue ;
        else
            return (false);
    }
    return (true);
}

bool    Conversion::isFloat(std::string str) {
    /*
        We have a float if the string is:
            1. a sequence of all numbers with maximum 1 decimal
            2. ending in the letter 'f';original string
    */
    int decimals = 0;
    
    for (std::string::size_type i = 0; i < str.size(); i++)
    {
        if (str[str.size() - 1] != 'f')
            return (false) ;
        if (str[i] >= 48 && str[i] <= 57)
            continue ;
        else if (i == 0 && str[i] == '-')
            continue ;
        else if (str[i] == '.' && i != (str.size() - 2))
        {
            decimals++;
            if (decimals > 1)
                return (false);
            continue ;
        }
        else if (i != str.size() - 1)
            return (false);
    }
    if (decimals != 1)
        return (false);
    return (true);
}

bool Conversion::isDouble(std::string str) {
    /*
        We have a double if the string has maximum one decimal
    */
    int decimals = 0;
    
    for (std::string::size_type i = 0; i < str.size(); i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
            continue ;
        else if (i == 0 && str[i] == '-')
            continue ;
        else if (str[i] == '.' && i != (str.size() - 1))
        {
            decimals++;
            if (decimals > 1)
                return (false);
            continue ;
        }
    }
    if (decimals != 1)
        return (false);
    return (true);
}

void    Conversion::printConversions(void) const {
    if (isConverted)
    {
        // CHAR FORMATTING
        if (this->c >= 32 && this->c <= 126)
            std::cout << "char: '" << this->c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        
        // INT
        std::cout << "int: " << this->i << std::endl;
         
        // FLOAT FORMATTING
        if (static_cast<int>(this->f) == this->f)
            std::cout << "float: " << this->f << ".0f" << std::endl;
        else
            std::cout << "float: " << this->f << "f" << std::endl;            

        // DOUBLE FORMATTING
        if (static_cast<int>(this->d) == this->d)
            std::cout << "double: " << this->d << ".0" << std::endl;
        else
            std::cout << "double: " << this->d << std::endl;

    }
    else if (str.compare("nan") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: nanf" << std::endl; 
        std::cout << "double: nan" << std::endl; 
    }
    else if (str.compare("+inf") == 0 || str.compare("+inff") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str.compare("-inf") || str.compare("-inff") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: -inff" << std::endl; 
        std::cout << "double: -inf" << std::endl;
    }
}