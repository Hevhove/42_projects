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

class NumberNotFoundException : public std::exception {
	virtual const char * what() const throw() {
		return "Number was not found in array";
	}
};

template <typename T> int easyfind(T container, int i)
{
	typename T::iterator it;
	typename T::iterator end = container.end();

	it = std::find(container.begin(), container.end(), i);
	if (it == end) {
		throw NumberNotFoundException();
		return (-1);
	}
	return (it - container.begin());
}

template <typename T> void	printElement(T el)
{
	std::cout << el << " ";
}
#endif
