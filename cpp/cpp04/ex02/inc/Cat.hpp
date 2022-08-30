/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 12:49:55 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CAT_HPP
# define CLASS_CAT_HPP
# include "../inc/AAnimal.hpp"
# include "../inc/Brain.hpp"
# include <iostream>

class Cat : public AAnimal {
    private:
        Brain* kittybrain;
        
    public:
        // Constructors
        Cat();
        virtual ~Cat();
        Cat(Cat const &src);
        Cat& operator=(Cat const & rhs);

        // Member functions
        void    makeSound(void) const;
        Brain*  getBrainAddr(void) const;
};

#endif