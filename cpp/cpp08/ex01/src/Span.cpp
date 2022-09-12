/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:34:43 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/12 20:41:49 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

// Constructors
Span::Span() : max_len(5) {
    vec.reserve(5);
}

Span::Span(unsigned int input_len) : max_len(input_len) {
    try {
        vec.reserve(max_len);
    } catch (std::length_error &e) {
        std::cout << e.what() << std::endl;
    }
}

Span::~Span() {
    ;
}

Span::Span(Span const & src) {
    this->max_len = src.max_len;
    vec = src.vec;
}

Span& Span::operator=(Span const & rhs) {
    this->max_len = rhs.max_len;
    vec = rhs.vec;
    return (*this);
}

// Getters
unsigned int    Span::getSize(void) {
    return (vec.size());
}

// Printing
void    Span::printSpan(void) {
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        int index = std::distance(vec.begin(), it);
        std::cout << vec[index] << " ";
    }
    std::cout << std::endl;
}

// Member functions
void    Span::addNumber(int num) {
    if (vec.size() < max_len)
        vec.push_back(num);
    else
        throw SpanFullException();
}

unsigned int    Span::longestSpan(void) {
    if (vec.size() == 0 || vec.size() == 1)
        throw EmptySpanException();
    
    return ( *(std::max_element(vec.begin(), vec.end())) - *(std::min_element(vec.begin(), vec.end())));
}

unsigned int    Span::shortestSpan(void) {
    unsigned int        sp = std::numeric_limits<unsigned int>::max();
    std::vector<int>    sorted_vec(vec);
    
    if (vec.size() == 0 || vec.size() == 1)
        throw EmptySpanException();
    
    std::sort(sorted_vec.begin(), sorted_vec.end());
    for (std::vector<int>::iterator it = sorted_vec.begin(); it + 1 != sorted_vec.end(); it++)
    {
        if (static_cast<unsigned int>((*(it + 1)) - *it) < sp)
            sp = (*(it + 1) - *it);
    }
    return (sp);
}

void            Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (vec.size() + end - begin > max_len)
        throw SpanFullException();
    else
        vec.insert(vec.end(), begin, end);
}

// Exceptions
const char * Span::EmptySpanException::what() const throw() {
    return ("Span empty or of size 1");
}

const char * Span::SpanFullException::what() const throw() {
    return ("Span is full, cannot add more elements");
}