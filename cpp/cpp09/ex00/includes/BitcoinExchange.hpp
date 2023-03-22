#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <regex>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double> _price_chart;

    public:
        // Constructors
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);

        // Member Functions
        void    parsePriceChart(const char* filename);
        void    viewTransactions(const char* filename);
        void    printPriceChart(void);
};

#endif