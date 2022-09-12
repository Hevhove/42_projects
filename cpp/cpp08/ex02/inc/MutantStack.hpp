/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:33:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/12 21:57:03 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <list>

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