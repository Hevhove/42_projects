/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:51 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 12:49:55 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DOG_HPP
# define CLASS_DOG_HPP
# include "../inc/AAnimal.hpp"
# include "../inc/Brain.hpp"
# include <iostream>

class Dog : public AAnimal {
    private:
        Brain* doggybrain;
       
    public:
        // Constructors
        Dog();
        virtual ~Dog();
        Dog(Dog const &src);
        Dog& operator=(Dog const & rhs);

        // Member functions
        void    makeSound(void) const;
        Brain*  getBrainAddr(void) const;
};

#endif