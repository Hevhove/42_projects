/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:49:34 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/13 13:54:56 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HUMANA_HPP 
# define CLASS_HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
    private:
        Weapon      _weapon;
        std::string _name;
    public:
        HumanA();
        ~HumanA();
        HumanA(const HumanA &old_obj);
        void    attack(void);
};

#endif