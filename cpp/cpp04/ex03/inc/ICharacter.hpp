/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:31:39 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 19:06:37 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ICHARACTER_HPP
# define CLASS_ICHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter {
    protected:
        std::string name;
        
    public:
        // Member functions
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif