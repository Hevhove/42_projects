/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:25:18 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/18 12:57:20 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        void    (Harl::*f[4])(void); // array of pointers to member functions
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);
        std::string array[4]; // array with complain level strings

};