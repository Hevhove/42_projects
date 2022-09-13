/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:33:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/13 12:58:14 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <list>
# include <algorithm>

/*
    A stack does not have iterators and is not an iterable container. However, it does have an underlying
    container from its parent class Deque. The underlying container object can be accessed via the correspondent
    data member c.

    Source: https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators  
*/

template <typename T> class MutantStack : public std::stack<T> {
    private:
        
    public:
        // Constructors 
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(MutantStack const & src){(*this = src);}
        MutantStack & operator=(MutantStack const & rhs){*this = rhs; return (*this);}

        // Member functions
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin(void){return (std::stack<T>::c.begin());} // using begin and end methods from the parent class here?
        iterator    end(void){return (std::stack<T>::c.end());} // using begin and end methods from the parent class here?

};

#endif