/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:51 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 11:16:53 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DOG_HPP
# define CLASS_DOG_HPP
# include "../inc/Animal.hpp"
# include <iostream>


class Dog : public Animal {
    private:
        
    public:
        // Constructors
        Dog();
        virtual ~Dog();
        Dog(Dog const &src);
        Dog& operator=(Dog const & rhs);

        // Member functions
        void    makeSound(void) const;
};

#endif