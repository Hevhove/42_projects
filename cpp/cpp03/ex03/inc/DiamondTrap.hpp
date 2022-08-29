/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:48:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 17:06:35 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DIAMONDTRAP_HPP
# define CLASS_DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    private:
        std::string name;

    public:
        // Constructors
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &src);
        virtual ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap &rhs);

        // Member functions
        virtual void    attack(const std::string& target);
        void            whoAmI();
};

#endif