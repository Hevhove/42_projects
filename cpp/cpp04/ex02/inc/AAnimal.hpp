/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:47:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 12:48:37 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_AAnimal_HPP
# define CLASS_AAnimal_HPP
# include <iostream>

class AAnimal {
    private:
        
    protected:
        std::string type;
        
    public:
        // Constructors
        AAnimal();
        virtual ~AAnimal();
        AAnimal(AAnimal const &src);
        AAnimal& operator=(AAnimal const & rhs);

        // Member functions
        virtual void    makeSound(void) const = 0;
        std::string     getType(void) const;
};

#endif