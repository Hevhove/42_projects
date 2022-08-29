/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:17:23 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:08 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FRAGTRAP_HPP
# define CLASS_FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:
        
    public:
        // Constructors
        FragTrap();
        FragTrap(std::string name, unsigned int hp = 100, unsigned int ep = 100, unsigned int ad = 30);
        FragTrap(FragTrap const &src);
        ~FragTrap();
        FragTrap& operator=(FragTrap const & rhs);

        // Member functions
        void    highFivesGuys(void);
};

#endif