/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:43:06 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/16 17:45:51 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_WEAPON_HPP
# define CLASS_WEAPON_HPP

# include <iostream>

class Weapon {
    private:
        std::string _type;
        
    public:
        Weapon();
        Weapon(std::string _type);
        ~Weapon();
        const std::string&  getType(void) const;
        void                setType(std::string type);
};

#endif