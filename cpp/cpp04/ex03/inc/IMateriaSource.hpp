/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:34:38 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/31 13:43:37 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_IMATERIASOURCE_HPP
# define CLASS_IMATERIASOURCE_HPP
# include "AMateria.hpp"

class IMateriaSource
{
    private:
        
    public:
        virtual ~IMateriaSource() {}; // Double brackets are important here! Otherwise it does not compile...
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif