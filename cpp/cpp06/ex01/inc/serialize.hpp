/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:27:14 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/08 10:48:27 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

// Headers
# include <iostream>

// Structs
struct Data {
    std::string name;
    int         legs;
    bool        isCool;
};

// Typedefs
typedef unsigned long uintptr_t;

// Function prototypes
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
void    printObject(Data object);

#endif