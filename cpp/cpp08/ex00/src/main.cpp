/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:54:55 by Hendrik           #+#    #+#             */
/*   Updated: 2022/09/10 19:32:45 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main(void)
{
	std::vector<int>	v1;
	int					to_find = 0;
	srand(time(NULL));

	std::cout << "[VECTOR TEST INT]" << std::endl;
	for(int i = 0; i < 10; i++)
		v1.push_back(rand() % 10);

	// print contents of vector
	std::for_each(v1.begin(), v1.end(), &printElement<int>);
	std::cout << std::endl;

	try {
		int return_val = easyfind(v1, to_find);
		std::cout << "Number:		" << to_find << std::endl << "Found at index:	" << return_val << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
