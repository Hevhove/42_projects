/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:38:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/12 18:19:53 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_ZOMBIE_H
# define CLASS_ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {
    private:
        std::string _name;
    public:
        // Constructors
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        // Member functions
        void    announce(void);
};

// Other functions
void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif