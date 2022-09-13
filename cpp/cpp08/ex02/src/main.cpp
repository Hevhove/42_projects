/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:04 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/09/13 13:00:15 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

int doubleList(int x)
{
    return (x * 2);
}

/*
    MAIN FROM SUBJECT
*/

int main() {
    MutantStack<int> mstack;
    std::list<int> list;

    // Basic Testing
    mstack.push(5);
    mstack.push(17);
    std::cout << "MSTACK TOP:           " << mstack.top() << std::endl;

    list.push_back(5);
    list.push_back(17);
    std::cout << "LIST BACK:            " << list.back() << std::endl << std::endl;

    mstack.pop();
    std::cout << "MSTACK SIZE:          "<< mstack.size() << std::endl;

    list.pop_back();
    std::cout << "LIST SIZE:            " << list.size() << std::endl << std::endl;

    // MutantStack Testing
    {
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "MSTACK ELEMENTS:      ";
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::stack<int> s(mstack);

        // Extra
        std::cout << std::endl << "TRANSFORM MSTACK:     ";
        std::transform(mstack.begin(), mstack.end(), mstack.begin(), doubleList);
        MutantStack<int>::iterator it2 = mstack.begin();
        MutantStack<int>::iterator ite2 = mstack.end();
        while (it2 != ite2)
        {
            std::cout << *it2 << " ";
            ++it2;
        }
        std::cout << std::endl;
    }
    
    // List Testing        
    {
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        std::cout << std::endl << "LIST ELEMENTS:        ";
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        
        // Extra
        std::cout << std::endl << "TRANSFORM LIST:       ";
        std::transform(list.begin(), list.end(), list.begin(), doubleList);
        std::list<int>::iterator it2 = list.begin();
        std::list<int>::iterator ite2 = list.end();
        while (it2 != ite2)
        {
            std::cout << *it2 << " ";
            ++it2;
        }
        std::cout << std::endl;
    }
    return 0;
}  