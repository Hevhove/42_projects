/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:43:06 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/13 13:49:02 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_WEAPON_HPP
# define CLASS_WEAPON_HPP

# include <iostream>

class Weapon {
    private:
        std::string type;
        
    public:
        Weapon();
        ~Weapon();
        const   std::string getType(void);
        void    setType(std::string type);
};

#endif