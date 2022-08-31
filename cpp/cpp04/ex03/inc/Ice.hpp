/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:27:20 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 13:58:31 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ICE_HPP
# define CLASS_ICE_HPP
# include <iostream>
# include "ICharacter.hpp"

class Ice : public AMateria {
    private:
        
    public:
        // Constructors
        Ice();
        virtual ~Ice();
        Ice(const Ice & src);
        Ice& operator=(const Ice &rhs);

        // Member functions
        Ice* clone() const;
        void use(ICharacter& target);
};

#endif