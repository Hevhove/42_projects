/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:42:07 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/26 18:02:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

float area(Point a, Point b, Point c) {
    float x1 = a.getX();
    float y1 = a.getY();
    float x2 = b.getX();
    float y2 = b.getY();
    float x3 = c.getX();
    float y3 = c.getY();

    return (abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0));
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    float A = area(a, b, c);
    float A1 = area(p, a, b);
    float A2 = area(p, a, c);
    float A3 = area(p, b, c);

    return (A == (A1 + A2 + A3));
}

int main( void )
{
    Point a(0.0f, 0.0f);
    Point b(20.0f, 0.0f);
    Point c(10.0f, 30.0f);
    Point p(15.0f, 15.0f);
    
    std::cout << "Is P inside of ABC: " << bsp(a, b, c, p) << std::endl;
    return (0);
}