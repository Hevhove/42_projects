/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:56:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/08 13:08:03 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BASE_HPP
# define CLASS_BASE_HPP
# include <iostream>
# include <cstdlib>

// Classes
class Base {
    private:
        
    public:
        // Constructor
        virtual ~Base();
};

class A : public Base {
    private:

    public:
};

class B : public Base {
    private:
        
    public:
        
};

class C : public Base {
    private:

    public:
};

// Functions
Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif