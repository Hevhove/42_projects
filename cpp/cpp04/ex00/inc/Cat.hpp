/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 11:16:50 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CAT_HPP
# define CLASS_CAT_HPP
# include "../inc/Animal.hpp"
# include <iostream>

class Cat : public Animal {
    private:
        
    public:
        // Constructors
        Cat();
        virtual ~Cat();
        Cat(Cat const &src);
        Cat& operator=(Cat const & rhs);

        // Member functions
        void    makeSound(void) const;
};

#endif