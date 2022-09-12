/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:15:48 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/12 21:00:17 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SPAN_HPP
# define CLASS_SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>
# include <cstdlib>

class Span {
    private:
        unsigned int max_len;
        std::vector<int> vec;
        
    public:
        // Constructors
        Span();
        Span(unsigned int input_len);
        virtual ~Span();
        Span(Span const & src);
        Span & operator=(Span const & rhs);
        
        // Getters
        unsigned int    getSize(void);
        
        // Printing
        void            printSpan(void);

        // Member functions
        void            addNumber(int num);
        unsigned int    longestSpan(void);
        unsigned int    shortestSpan(void);
        void            addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        
        // Exceptions
        class EmptySpanException : std::exception {
            public:
                const char * what () const throw ();
        };

        class SpanFullException : std::exception {
            public:
                const char * what () const throw ();
        };
};

#endif