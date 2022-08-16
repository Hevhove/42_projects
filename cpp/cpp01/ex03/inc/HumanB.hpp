/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:14:03 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/16 17:31:13 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HUMANB_HPP
# define CLASS_HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
    private:
        std::string     _name;
        Weapon*         _weapon;

    public:
        HumanB(std::string _name);
        ~HumanB();
        Weapon  getWeapon(void) const;
        void    setWeapon(Weapon& _weapon);
        void    attack(void);
};

#endif