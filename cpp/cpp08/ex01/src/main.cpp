/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:59:29 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/12 21:00:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "[SUBJECT]" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl << std::endl;
    
    std::cout << "[TEST ADD RANGE OF NUMBERS]"<< std::endl;
    Span sp1 = Span(10);
    static const int arr[] = {10, 4, 11, 2};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    sp1.addNumber(1);
        
    std::cout << "Original Span :       ";
    sp1.printSpan();
    sp1.addNumbers(vec.begin(), vec.end());
    
    std::cout << "New Span      :       ";
    sp1.printSpan();
    

    std::cout << std::endl << "[TEST ADDING TOO MANY NUMBERS]"<< std::endl;
    try {
        static const int arr2[] = {1, 1, 2, 3, 5, 8, 13, 21};
        std::vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
        sp1.addNumbers(vec2.begin(), vec2.end());
    } catch (Span::SpanFullException& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}