/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:29:50 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/08 18:42:24 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"

int main(void)
{
    int a = 7;
    int b = 9;

    
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << max<int>(a, b) << std::endl;
    
    std::cout << "Min of " << a << " and " << b << " is ";
    std::cout << min<int>(a, b) << std::endl;

    std::cout << "a is now: " << a << std::endl;
    std::cout << "b is now: " << b << std::endl;
    swap<int>(a, b);
    std::cout << "a is now: " << a << std::endl;
    std::cout << "b is now: " << b << std::endl;

    return (0);
}