/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:30:04 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/09 17:43:21 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include "../inc/Awesome.hpp"
#define ARRAY_LEN 5

int main(void)
{
    int     a[ARRAY_LEN] = {5, 7 , 4, 5, 1};
    float   b[ARRAY_LEN] = {5, 7 , 4, 5, 1};
    char    c[ARRAY_LEN] = {'*', '%', ' ', '('};
    
    // Transform array a
    std::cout << "[ARRAY A]" << std::endl;
    iter(a, ARRAY_LEN, multiplyBy2<int>);
    for (int i = 0; i < ARRAY_LEN; i++)
        std::cout << a[i] << std::endl;

    // Transform array b
    std::cout << std::endl << "[ARRAY B]" << std::endl;
    iter(b, ARRAY_LEN, multiplyBy2<float>);
    for (int i = 0; i < ARRAY_LEN; i++)
        std::cout << b[i] << std::endl;

    // Transform array c
    std::cout << std::endl << "[ARRAY C]" << std::endl;
    iter(c, ARRAY_LEN, multiplyBy2<char>);
    for (int i = 0; i < ARRAY_LEN; i++)
        std::cout << c[i] << std::endl;
}

// int main() {
//     int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//     Awesome tab2[5];
    
//     iter( tab, 5, print);
//     iter( tab2, 5, print);
//     return 0;
// }