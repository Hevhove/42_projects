/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:02:35 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 18:50:37 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        AMateria*       inventory[4];
        unsigned int    weaponCount;

    protected:
        std::string name;
        
    public:
        // Constructors
        Character();
        Character(std::string name);
        virtual ~Character();
        Character(const Character & src);
        Character& operator=(const Character &rhs);

        // Member functions
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};