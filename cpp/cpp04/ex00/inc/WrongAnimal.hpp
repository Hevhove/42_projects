/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:47:54 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 10:35:17 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_WRONGANIMAL_HPP
# define CLASS_WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal {
    private:
        
    protected:
        std::string type;
        
    public:
        // Constructors
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(WrongAnimal const &src);
        WrongAnimal& operator=(WrongAnimal const & rhs);

        // Member functions
        void    makeSound(void) const;
        std::string     getType(void) const;
};

#endif