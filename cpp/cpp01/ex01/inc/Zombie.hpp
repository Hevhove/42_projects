/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:48:58 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/12 18:38:52 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ZOMBIE_HPP
# define CLASS_ZOMBIE_HPP
# include <iostream>
# include <string>
# include <cstdlib>

class Zombie {
    private:
        std::string _name;
        
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
        void    setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif