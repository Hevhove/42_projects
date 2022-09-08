/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:06:02 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/08 13:21:33 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

Base::~Base() {
    
}

Base*   generate(void) {
    // It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
    // to use anything you like for the random choice implementation.

    int randNum = (rand() % 3) + 1;
    switch (randNum)
    {
        case 1:
            return (new A);
        case 2:
            return (new B);
        default:
            return (new C);
    }
}

void    identify(Base* p) {
    // It prints the actual type of the object pointed to by p: "A", "B" or "C".
    /*
        We need to use dynamic casting in this case. Dynamic casting is mainly used to safely downcast.
        This means casting a base class pointer (or reference) to a derived class pointer.

        This is exactly what we will be doing in this exercise, as we want to identify
        what the type is of the Base pointer.
    */
    if (p == NULL)
        std::cout << "Provided pointer is NULL" << std::endl;
    else if (dynamic_cast<A*>(p) != NULL) // if the cast is successful, the Base class is A
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Failed type identification" << std::endl;
}

void    identify(Base &p)
{
    // With references, the problem is that they cannot equal to NULL
    // Because of this, we should use a try-catch block to catch if the cast fails
    try 
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } 
    catch (const std::exception& e) 
    {
        try 
        {
            B b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::exception& e)
        {
            try
            {
                C c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << "Failed type identification" << std::endl;
            }
        }
    }
}