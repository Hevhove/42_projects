/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:57:44 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/08/17 12:00:23 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sed_is_for_losers.hpp"

int main(int argc, char* argv[])
{
    std::string filename;
    std::string line;
    std::size_t sub;
    int i = 0;

    if (argc != 4)
    {
        std::cout << "Usage: ./sed <filename> <string> <replacing string>" << std::endl;
        return (0);
    }
    filename = argv[1] + std::string(".replace");
    std::ifstream ifs(argv[1]);
    if (!ifs.is_open() || ifs.fail())
    {
        std::cout << "File cannot be opened/doesn't exist..." << std::endl;
        return (0);
    }
    std::ofstream ofs(filename.c_str());
    if (!ofs.is_open() || ofs.fail())
    {
        std::cout << "File cannot be opened/doesn't exist..." << std::endl;
        return (0);
    }
    std::string word = argv[2];
    std::string replace = argv[3];
    while (getline(ifs, line))
    {
        i = 0;
        while (1)
        {
            sub = line.find(argv[2], i); // find the pos of the searched string and put it in sub, as of pos i;
            if (sub != std::string::npos) // if the substring was found in this line (line.find returns npos if the word was not found)
            {
                ofs << line.substr(i, sub - i) << replace; // put everything until sub - i into the ofs, then append replace
                i = sub + word.length();
            }
            else
                break ;
        }
        ofs << &line[i] << std::endl; // append the remainder of the line into the ofs
    }
}