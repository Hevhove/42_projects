#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
    _price_chart = src._price_chart;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    _price_chart = rhs._price_chart;
    return (*this);
}

// Helper functions

bool isValidDateString(const std::string& dateString) {
  if (dateString.length() != 10) {
    // Invalid string length
    return false;
  }

  // Extract year, month, and day from the input string
  int year = 0, month = 0, day = 0;
  for (int i = 0; i < 10; i++) {
    char c = dateString[i];
    if (i == 4 || i == 7) {
      // Separator character should be a hyphen
      if (c != '-') {
        return false;
      }
    } else if (c >= '0' && c <= '9') {
      // Accumulate digits
      int digit = c - '0';
      if (i < 4) {
        year = year * 10 + digit;
      } else if (i < 7) {
        month = month * 10 + digit;
      } else {
        day = day * 10 + digit;
      }
    } else {
      // Invalid character
      return false;
    }
  }

  // Invalid year range
  if (year < 1900 || year > 9999) {
    return false;
  }

  // Invalid month range
  if (month < 1 || month > 12) {
    return false;
  }

  // Check for leap year
  int daysInMonth = 31;
  if (month == 2) {
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    daysInMonth = isLeapYear ? 29 : 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    daysInMonth = 30;
  }

  // Invalid day range
  if (day < 1 || day > daysInMonth) {
    return false;
  }

  // Valid date string
  return true;
}

static std::string trimTrailingSpace(const std::string& str) {
  std::size_t last = str.find_last_not_of(" ");
  if (last == std::string::npos) {
    return "";
  }
  return str.substr(0, last + 1);
}

// Member Functions
void    BitcoinExchange::parsePriceChart(const char* inputFileName) {
    std::string line;
    int         count = 0;
    std::ifstream csv_file(inputFileName);

    if (!csv_file.is_open())
        throw std::runtime_error("Error: could not open csv file");
    while (std::getline(csv_file, line))
    {
        // Skip the headers
        if (count++ == 0)
            continue ;
        std::stringstream ss(line);
        std::string date_str, price_str;

        // Date String
        std::getline(ss, date_str, ',');

        // Amount String
        std::getline(ss, price_str);
        double price = std::atof(price_str.c_str());
        _price_chart[date_str] = price;

        count++;
    }
}

void    BitcoinExchange::viewTransactions(const char* inputFileName) {
    std::string line;
    int         count = 0;
    std::ifstream csv_file(inputFileName);

    if (!csv_file.is_open())
        throw std::runtime_error("Error: could not open input file");
    while (std::getline(csv_file, line))
    {
        // Skip the headers
        if (count++ == 0)
            continue ;
        std::stringstream ss(line);
        std::string date_str, amount_str;

        // Date String
        std::getline(ss, date_str, '|');
        if (!isValidDateString(trimTrailingSpace(date_str)))
        {
            std::cout << "Error: bad input => " << date_str << std::endl;
            continue ;
        }

        // Amount String
        std::getline(ss, amount_str);
        double amount = std::atof(amount_str.c_str());
        if (amount < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue ;
        }
        else if (amount >= 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue ;
        }

        std::map<std::string, double>::iterator it = _price_chart.lower_bound(date_str);
        if (it != _price_chart.begin())
            --it;
        double transactionValue = amount * it->second;
        std::cout << date_str << "=>" << amount_str << " = " << transactionValue << std::endl;
    }
}

void BitcoinExchange::printPriceChart(void) {
    std::map<std::string, double>::const_iterator it;

    std::cout << "Printing Price Chart ...";
    for (it = _price_chart.begin(); it != _price_chart.end(); ++it) {
        std::cout << "  " << it->first << " => " << it->second << std::endl;
    }
}