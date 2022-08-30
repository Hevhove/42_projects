/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:16:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 19:13:00 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_AMATERIA_HPP
# define CLASS_AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
    protected:
        std::string type;
    public:
        // Constructors
        AMateria();
        AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria(const AMateria & src);
        AMateria& operator=(const AMateria &rhs);
        
        // Member functions
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif