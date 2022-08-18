/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:28:04 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/18 12:57:05 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char* argv[])
{
    Harl harl;

    if (argc == 2)
    {
        harl.complain(argv[1]);
    }
    else
    {
        std::cout << "Usage: ./harlFilter <MESSAGE>" << std::endl;
    }
}