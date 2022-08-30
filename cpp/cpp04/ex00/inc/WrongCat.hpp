/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:49 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:45:45 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_WRONGCAT_HPP
# define CLASS_WRONGCAT_HPP
# include "../inc/WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal {
    private:
        
    public:
        // Constructors
        WrongCat();
        virtual ~WrongCat();
        WrongCat(WrongCat const &src);
        WrongCat& operator=(WrongCat const & rhs);

        // Member functions
        void    makeSound(void) const;
};

#endif