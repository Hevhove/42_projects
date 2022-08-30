/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:22:57 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 11:45:07 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BRAIN_HPP
# define CLASS_BRAIN_HPP
# include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain(Brain const &src);
        Brain& operator=(Brain const & rhs);
};

#endif