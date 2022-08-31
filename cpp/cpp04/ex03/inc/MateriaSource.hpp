/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:51:23 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 13:42:09 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_MATERIASOURCE_HPP
# define CLASS_MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        int       weaponCount;
        AMateria* inventory[4];
        
    public:
        // Constructors 
        MateriaSource();
        ~MateriaSource();
        
        // Member functions
        void    learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};

#endif