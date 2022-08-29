/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:48:42 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 17:13:58 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CLAPTRAP_HPP
# define CLASS_CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
    protected:
        std::string     name;
        unsigned int    hp;
        unsigned int    ep;
        unsigned int    ad;

    public:
        // Constructors
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& src);
        virtual ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& rhs);

        // Member functions
        std::string     getName();
        virtual void    attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
};

#endif