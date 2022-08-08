/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:59:10 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/08 15:23:42 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/megaphone.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; j < (int)strlen(argv[i]); j++)
                std::cout << (char)toupper(argv[i][j]);
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
