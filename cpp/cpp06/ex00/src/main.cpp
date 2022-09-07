/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:41:17 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/07 19:04:44 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Conversion.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "USAGE: ./convert {user string}" << std::endl;
        return (0);
    }
    Conversion conversion = Conversion(argv[1]);
    conversion.print();
}