/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:51 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:45:47 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_WRONGDOG_HPP
# define CLASS_WRONGDOG_HPP
# include "../inc/WrongAnimal.hpp"
# include <iostream>

class WrongDog : public WrongAnimal {
    private:
        
    public:
        // Constructors
        WrongDog();
        virtual ~WrongDog();
        WrongDog(WrongDog const &src);
        WrongDog& operator=(WrongDog const & rhs);

        // Member functions
        void    makeSound(void) const;
};

#endif