/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:25:47 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 17:54:42 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CURE_HPP
# define CLASS_CURE_HPP
# include <iostream>
# include "ICharacter.hpp"

class Cure : public AMateria {
    private:
        
    public:
        // Constructors
        Cure();
        Cure(std::string type);
        virtual ~Cure();
        Cure(const Cure & src);
        Cure& operator=(const Cure &rhs);

        // Member functions
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif