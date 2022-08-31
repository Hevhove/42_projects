/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:47:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 12:24:52 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ANIMAL_HPP
# define CLASS_ANIMAL_HPP
# include <iostream>

class Animal {
    private:
        
    protected:
        std::string type;
        
    public:
        // Constructors
        Animal();
        virtual ~Animal();
        Animal(Animal const &src);
        Animal& operator=(Animal const & rhs);

        // Member functions
        virtual void    makeSound(void) const;
        std::string     getType(void) const;
};

#endif