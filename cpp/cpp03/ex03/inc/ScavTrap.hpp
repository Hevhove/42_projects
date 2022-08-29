/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:35:32 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 17:03:55 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SCAVTRAP_HPP
# define CLASS_SCAVTRAP_HPP
# include <ClapTrap.hpp>

class ScavTrap : virtual public ClapTrap {
    private:
        
    public:
        // Constructors
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);
        virtual ~ScavTrap();
        ScavTrap& operator=(ScavTrap const & rhs);

        // Member functions
        virtual void    attack(const std::string& target);
        void            guardGate();
};

#endif