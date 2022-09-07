/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:50:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/07 19:16:50 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Conversion.hpp"

// Parametrical Constructors
Conversion::Conversion(){

}

Conversion::Conversion(std::string input){
    for (int i = 0; i < 4; i++)
        conversion_table[i].status = NOT_CONVERTED;
    
    conversion_table[T_CHAR].conversionFunction = &Conversion::convertToChar;
    conversion_table[T_INT].conversionFunction = &Conversion::convertToInt;
    conversion_table[T_FLOAT].conversionFunction = &Conversion::convertToFloat;
    conversion_table[T_DOUBLE].conversionFunction = &Conversion::convertToDouble;
    conversion_table[T_NONE].conversionFunction = &Conversion::allImpossible;

    (this->*(conversion_table[getType(input)].conversionFunction))(input);
}

Conversion::~Conversion(){
    
}

Conversion::Conversion(const Conversion & src) {
    for (size_t i = 0; i < NB_TYPE_CONVERSIONS; i++)
		conversion_table[i].status = src.conversion_table[i].status;
	converted = src.converted;
}

Conversion& Conversion::operator=(const Conversion & rhs) {
    for (size_t i = 0; i < NB_TYPE_CONVERSIONS; i++)
		conversion_table[i].status = rhs.conversion_table[i].status;
	converted = rhs.converted;
    return (*this);    
}

Conversion::t_types    Conversion::getType(const std::string &str)
{
    if (isChar(str))
        return (T_CHAR);
    else if (isInt(str))
        return (T_INT);
    else if (isFloat(str))
        return (T_FLOAT);
    else if (isDouble(str))
        return (T_DOUBLE);
    else
        return (T_NONE);   
}

bool    Conversion::isChar(const std::string &str) {
    if (str.length() == 1 && !std::isdigit(str[0]))
        return (true);
    else
        return (false);
}

bool    Conversion::isInt(const std::string &str) {
    int len = str.length();
    int i;

    if (str[0] == '-')
        i = 1;
    else
        i = 0;
    if (len == i)
        return (false);
    for (; i < len; i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool Conversion::isFloat(const std::string &str) {
    size_t i = 0;

    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
    if (str[0] == '-')
        i++;
    while (std::isdigit(str[i]))
        i++;
    if (i + 1 == str.length() && str[i] == 'f')
        return (true);
    if (i + 1 != str.length() && str[i] != '.')
        return (false);
    else
        i++;
    while (std::isdigit(str[i]))
        i++;
    if (i + 1 != str.length() || str[i] != 'f')
        return (false);
    return (true);
}

bool Conversion::isDouble(const std::string &str) {
    size_t i = 0;

    if (str == "-inf" || str == "+inf" || str == "nan")
        return (true);
    if (str[0] == '-')
        i++;
    while (std::isdigit(str[i]))
        i++;
    if (str[i] != '.')
        return (false);
    i++;
    while (std::isdigit(str[i]))
        i++;
    if (i != str.length())
        return (false);
    return (true);
}

Conversion::t_status    Conversion::setCharStatus(const char &c)
{
    if (std::isprint(c))
        return (CONVERTED);
    else
        return (NON_DISPLAYABLE);
}

std::string Conversion::convertToString(int integer)
{
    std::string         convertedString;
    std::stringstream   stringstream;

    stringstream << integer;
    stringstream >> convertedString;

    return (convertedString);
}

void    Conversion::convertToChar(const std::string &str)
{
    // Converting char
    std::stringstream stringstream(str);
    stringstream >> converted.c;
    conversion_table[T_CHAR].status = setCharStatus(converted.c);

    // Converting the other types explicitly
    converted.i = static_cast<int>(converted.c);
    conversion_table[T_INT].status = CONVERTED;
    converted.f = static_cast<float>(converted.c);
    conversion_table[T_FLOAT].status = CONVERTED;
    converted.d = static_cast<double>(converted.c);
    conversion_table[T_DOUBLE].status = CONVERTED;
}

void    Conversion::convertToInt(const std::string &str) {
    // Converting Int
    std::stringstream stringstream(str);
    stringstream >> converted.i;
    if (convertToString(converted.i) != str)
        allImpossible(str);
    else
    {
        conversion_table[T_INT].status = CONVERTED;

        converted.c = static_cast<char>(converted.i);
        conversion_table[T_CHAR].status = setCharStatus(converted.c);
        converted.f = static_cast<float>(converted.i);
        conversion_table[T_FLOAT].status = CONVERTED;
        converted.d = static_cast<double>(converted.i);
        conversion_table[T_DOUBLE].status = CONVERTED;

    }
}

void    Conversion::convertToFloat(const std::string &str)
{
    if ( str == "+inff")
        converted.f = 1.0 / 0.0 ;
    else if (str == "-inff")
        converted.f = -1.0 / 0.0 ;
    else if (str == "nanf")
        converted.f = std::numeric_limits<float>::quiet_NaN();
    else
        converted.f = setFloat(str);
    conversion_table[T_FLOAT].status = CONVERTED;

    // Explicitly converting the other types
    converted.i = static_cast<int>(converted.f);
    if (converted.i != static_cast<long long>(converted.f))
    {
        conversion_table[T_INT].status = IMPOSSIBLE;
        converted.c = static_cast<char>(converted.f);
        conversion_table[T_CHAR].status = setCharStatus(converted.c);
    }
    converted.d = static_cast<double>(converted.f);
    conversion_table[T_DOUBLE].status = CONVERTED;
}

float   Conversion::setFloat(const std::string &str)
{
    std::stringstream   stringstream(str);
    double              tmp;

    stringstream >> tmp;
    if (tmp > std::numeric_limits<float>::max())
        return (1./0.);
    else
        return ((float)tmp);
}

double Conversion::setDouble(const std::string &str)
{
    std::stringstream   stringstream(str);
    long double         tmp;

    stringstream >> tmp;
    if (tmp > std::numeric_limits<double>::max())
        return (1.0 / 0.0);
    else
        return ((double)tmp);
}

void    Conversion::convertToDouble(const std::string &str)
{
    // Converting double
    if (str == "+inf")
        converted.d = 1.0 / 0.0;
    else if (str == "-inf")
        converted.d = -1.0 / 0.0;
    else if (str == "nan")
        converted.d = std::numeric_limits<double>::quiet_NaN();
    else
        converted.d = setDouble(str);
    conversion_table[T_DOUBLE].status = CONVERTED;

    // Explicitly converting
    converted.i = static_cast<int>(converted.d);
    if (converted.i != static_cast <long long>(converted.d))
    {
        conversion_table[T_INT].status = IMPOSSIBLE;
        conversion_table[T_CHAR].status = IMPOSSIBLE;
    }
    else
    {
        conversion_table[T_INT].status = CONVERTED;
        converted.c = static_cast<char>(converted.d);
        conversion_table[T_CHAR].status = setCharStatus(converted.c);
    }
    converted.f = static_cast<float>(converted.d);
    conversion_table[T_FLOAT].status = CONVERTED;
}

void    Conversion::allImpossible(const std::string &str)
{
    (void)str;  
    for (size_t i = 0; i < NB_TYPE_CONVERSIONS; i++)
        conversion_table[i].status = IMPOSSIBLE;
}

void    Conversion::print(void) const
{
    std::cout << "char: ";
    if (!printError(conversion_table[T_CHAR].status))
        std::cout << "'" << converted.c << "'" << std::endl;
    std::cout << "int: ";
    if (!printError(conversion_table[T_INT].status))
        std::cout << converted.i << std::endl;
    std::cout << "float: ";
    if (!printError(conversion_table[T_FLOAT].status))
        std::cout << std::fixed << std::setprecision(1) << converted.f << "f" << std::endl;
    std::cout << "double: ";
    if (!printError(conversion_table[T_DOUBLE].status))
        std::cout << std::fixed << std::setprecision(1) << converted.d << std::endl;

}

bool    Conversion::printError(int status) const
{
    switch (status)
    {
        case IMPOSSIBLE:
            std::cout << "Impossible" << std::endl;
            return (true);
        case NON_DISPLAYABLE:
            std::cout << "Non displayable" << std::endl;
            return (true);
        default:
            return (false);
    }
}