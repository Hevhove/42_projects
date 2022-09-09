/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:04:38 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/09 17:58:38 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ARRAY_HPP
# define CLASS_ARRAY_HPP
# include <iostream>
# include <time.h>       /* time */
# include <stdio.h>      /* printf, NULL */
# include <stdlib.h>     /* srand, rand */

template <typename T> class Array {
    private:
        T*              arr;
        unsigned int    len;
    public:
        // Constructors
        Array() : arr(new T[0]), len(0) {}
        Array(unsigned int n) : arr(new T[n]), len(n) {}
        
        // Destructor
        ~Array(){ delete[] arr;}

        // Copy and assigment constructors
        Array(Array & src) : arr(new T[src.len]), len(src.len) {
            for (unsigned int i = 0; i < src.len; i++)
                arr[i] = src[i];
        }
        
        Array<T>& operator = (Array<T> & rhs) {
            delete[] arr;
            this->len = rhs.len;
            arr = new T[rhs.len];
            for (unsigned int i = 0; i < rhs.len; i++)
                arr[i] = rhs[i];
            return (*this);
        }

        const Array<T>& operator = (Array<T> const & rhs) {
            delete[] arr;
            this->len = rhs.len;
            arr = new T[rhs.len];
            for (unsigned int i = 0; i < rhs.len; i++)
                arr[i] = rhs[i];
            return (*this);
        }

        // Indexing overload
        T & operator[](unsigned int const & index) {
            if (index < len)
                return (arr[index]);
            else
                throw OutOfBoundsException();
        }

        const T & operator[](unsigned int const & index) const {
            if (index < len)
                return (arr[index]);
            else
                throw OutOfBoundsException();
        }

        class OutOfBoundsException : public std::exception {
            const char * what() const throw () {
                return "Index out of bounds";
            }
        };

        // Getters
        unsigned int    getSize(){
            return (this->len);
        }

        // printing
        void    print(void) const {
            for (unsigned int i = 0; i < len ; i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
        }
};

#endif