/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:30:06 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/08 18:42:41 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T> T const & max(T const & x, T const & y)
{
    return ((x > y) ? x : y);
}

template <typename T> T const & min(T const & x, T const & y)
{
    return ((x < y) ? x : y);
}

template <typename T> void swap(T & x, T & y)
{
    T tmp;

    tmp = x;
    x = y;
    y = tmp;
}

#endif