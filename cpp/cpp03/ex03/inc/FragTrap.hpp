/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:17:23 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/29 17:03:47 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FRAGTRAP_HPP
# define CLASS_FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    private:
        
    public:
        // Constructors
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &src);
        virtual ~FragTrap();
        FragTrap& operator=(FragTrap const & rhs);

        // Member functions
        virtual void attack(const std::string& target);
        void         highFivesGuys(void);
};

#endif