/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:28:04 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/18 14:33:56 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char* argv[])
{
    Harl        harl;
    std::string level;
    int         index;
    
    if (argc == 2)
    {
        level = argv[1];
        for (int i = 0; i < 4; i++)
        {
            if (level.compare(harl.array[i]) == 0)
            {
                index = i;
                break ;
            }
                
        }
        // Fallthrough behaviour is forbidden by flags, so instead of this we must duplicate statements in the below switch statement.
        switch (index)
        {
            case 0:
                harl.complain(harl.array[0]);
                harl.complain(harl.array[1]);
                harl.complain(harl.array[2]);
                harl.complain(harl.array[3]);
                break ;
            case 1:
                harl.complain(harl.array[1]);
                harl.complain(harl.array[2]);
                harl.complain(harl.array[3]);
                break ;
            case 2:
                harl.complain(harl.array[2]);
                harl.complain(harl.array[3]);
                break ;
            case 3:
                harl.complain(harl.array[3]);
                break ;
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
                break ;

        }
    }
    else
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}