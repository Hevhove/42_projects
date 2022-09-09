/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:12:12 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/09 16:44:22 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T, typename U> void iter(T* arr, size_t len, U func)
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T> void iter(T* arr, size_t len, void(*func)(T const &))
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

// To test the above template, we need type-agnostic function templates
template <typename T> void multiplyBy2(T & x)
{
    x *= 2;
}

#endif