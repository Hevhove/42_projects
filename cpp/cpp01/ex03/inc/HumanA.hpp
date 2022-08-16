/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:49:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/16 17:49:06 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HUMANA_HPP 
# define CLASS_HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon&     _weapon;
    
    public:
        HumanA(std::string _name, Weapon& weapon);
        ~HumanA();
        Weapon  getWeapon(void) const;
        void    attack(void);
};

#endif