/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:41:45 by Hendrik           #+#    #+#             */
/*   Updated: 2022/09/10 19:27:43 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <array>
# include <algorithm>

/*
	The STL has 4 components we can leverage:
		1. Algorithms
		2. Containers
		3. Functions
		4. Iterators

	Containers can include Vectors, Arrays, Deques, ... We can iterate over them (they are not continuous spaces in memory) by using
	iterators. Checking reference https://cplusplus.com/reference/stl we notice every container has a const_iterator. We will return
	the const iterator for this exercise.

	The find() function is a part of the STL and will return the desired element within a specified range. We don't even need
	to loop over the iterators!
*/

template <typename T> typename T::const_iterator easyfind(T container, int i)
{
	return (find(container.begin(), container.end(), i));
}

template <typename T> void	printElement(T el)
{
	std::cout << el << " ";
}
#endif
