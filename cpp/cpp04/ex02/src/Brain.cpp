/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:28:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/30 11:45:31 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain was constructed" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain was destructed" << std::endl;
}

Brain::Brain(Brain const &src){
    std::cout << "Brain was copied" << std::endl;
    (void)src;
}

Brain& Brain::operator=(Brain const & rhs) {
    std::cout << "Brain assignment operator called" << std::endl;;
    (void)rhs;
    return (*this);
}