/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:02:45 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/09 17:58:06 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main(void)
{
    Array<int>          arr1;
    Array<double>       arr2(10);
    Array<double>       arr3(arr2); // copy operator
    const Array<int>    arr4(5);
    
    srand(time(NULL));

    // Assign into array
    for (unsigned int i = 0; i < 10; i++)
    {
        const double num = static_cast<double>(rand() % 10);
        arr2[i] = num;
    }
    arr2.print();

    // Testing copy and assignment operator
    arr2[0] = 1;
    arr3 = arr2;
    arr3.print();
    
    // Testing size function
    std::cout << "size is " << arr3.getSize() << std::endl;

    // Index out of bounds
    try {
        arr3[-1] = 12.0;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    // Below test fails because we cannot write to a const instance of Array
    // try 
    // {
    //     arr4.print();
    //     for (unsigned int i = 0; i < 5; i++)
    //         arr4[i] = rand() % 5;
    //     arr4.print();
    // } catch (std::exception& e){
    //     std::cout << e.what() << std::endl;
    // }
    
    return (0);
}