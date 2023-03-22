#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    BitcoinExchange btc_exchange;

    // Check arguments
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (-1);
    }

    // Parse input file
    try {
        btc_exchange.parsePriceChart("data/data.csv");
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Create Exchange and viewBalances
    btc_exchange.viewTransactions(argv[1]);
    return (0);
}