/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:27:26 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/08 10:53:36 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/serialize.hpp"

/*
    SERIALIZATION
    
    Serialization is the process of converting a data object - a combination of
    code and data represented within a region of data storage - into a series of
    bytes that saves the state of the object in an easily transmittable form.

    The serialized form, is used to deliver the data to another data store (such
    as in-memory computer platform), application or some other destination.

    The reverse process is called deserialization.
*/

int main(void)
{
    Data        dataObject;
    uintptr_t   serializedObject;
    Data*        deserializedObject;

    // assign data into the object
    dataObject.name = "Hendrik";
    dataObject.legs = 2;
    dataObject.isCool = true;

    // print original object
    std::cout << "[ORIGINAL OBJECT]" << std::endl;
    printObject(dataObject);

    // serialize the object
    serializedObject = serialize(&dataObject);
    
    // deserialize the object
    deserializedObject = deserialize(serializedObject);

    // print comparison between original object and deserialized object
    std::cout << "[DESERIALIZED OBJECT]" << std::endl;
    printObject(*deserializedObject);
    std::cout << "[ORIGINAL OBJECT]" << std::endl;
    printObject(dataObject);
}

uintptr_t   serialize(Data* ptr)
{
    // Takes a pointer and converts it to the bytestream uintptr_t
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   deserialize(uintptr_t raw)
{
    // takes the unsigned integer parameter and converts it back to the Data object
    return (reinterpret_cast<Data*>(raw));
}

void    printObject(Data object)
{
    std::cout << "[PRINTING DATA OBJECT]" << std::endl;
    std::cout << "Name: " << object.name << std::endl;
    std::cout << "Legs: " << object.legs << std::endl;
    std::cout << "Cool: " << object.isCool << std::endl << std::endl;
}