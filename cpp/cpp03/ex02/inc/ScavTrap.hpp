/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:35:32 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:12 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SCAVTRAP_HPP
# define CLASS_SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:
        
    public:
        // Constructors
        ScavTrap();
        ScavTrap(std::string name, unsigned int hp = 100, unsigned int ep = 50, unsigned int ad = 20);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap();
        ScavTrap& operator=(ScavTrap const & rhs);

        // Member functions
        void    guardGate();
};

#endif