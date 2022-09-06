/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:12:22 by Hendrik           #+#    #+#             */
/*   Updated: 2022/09/06 10:53:06 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Conversion.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Please provide 1 argument to the program" << std::endl;
		return (-1);
	}
	Conversion conversion(argv[1]);
	conversion.printConversions();
	return (0);
}
