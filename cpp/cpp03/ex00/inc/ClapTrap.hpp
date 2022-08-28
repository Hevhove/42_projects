/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:48:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/28 12:27:35 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CLAPTRAP_HPP
# define CLASS_CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
    private:
        std::string     name;
        unsigned int    hp;
        unsigned int    ep;
        unsigned int    ad;
        
    public:
        // Constructors
        ClapTrap();
        ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap();
        ClapTrap& operator=(ClapTrap const & rhs);
        
        // Member functions
        void            attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);

        // Getters
        unsigned int    get_hp(void);
        unsigned int    get_ep(void);
        unsigned int    get_ad(void);
        
};

#endif