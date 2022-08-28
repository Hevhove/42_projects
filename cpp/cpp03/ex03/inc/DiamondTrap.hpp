/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:42:23 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/28 16:54:45 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DIAMONDTRAP_HPP
# define CLASS_DIAMONDTRAP_HPP
# include "../inc/FragTrap.hpp"
# include "../inc/DiamondTrap.hpp"

class DiamondTrap : public FragTrap, public DiamondTrap {
    private:
        std::string name;
    public:
        // Constructors
        FragTrap();
        FragTrap(std::string name, unsigned int hp = 100, unsigned int ep = 100, unsigned int ad = 30);
        FragTrap(FragTrap const &src);
        ~FragTrap();
        FragTrap& operator=(FragTrap const & rhs);

        // Member functions
        void    whoAmI(void);        
}

#endif