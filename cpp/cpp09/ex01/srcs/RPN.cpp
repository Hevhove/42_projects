#include "RPN.hpp"

// Helper functions
static bool isInteger(const std::string& str) {
  if (str.empty()) {
    return false;
  }

  // check characters
  for (unsigned long i = 0; i < str.size(); ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}


// Constructors
RPN::RPN() {
    //
}

RPN::RPN(std::string eqStr) {
    std::stack<double>  RPNStack;
    std::stringstream   ss(eqStr);
    std::string         token;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (RPNStack.size() < 1)
            {
                std::cout << "Error" << std::endl;
                exit(-1);
            }
            // operator
            double op2 = RPNStack.top();
            RPNStack.pop();
            double op1 = RPNStack.top();
            RPNStack.pop();

            // perform operation
            if (token == "+")
                RPNStack.push(op1 + op2);
            else if (token == "-")
                RPNStack.push(op1 - op2);
            else if (token == "*")
                RPNStack.push(op1 * op2);
            else if (token == "/")
                RPNStack.push(op1 / op2);
        }
        else if (isInteger(token))
        {
            // operand
            RPNStack.push(std::atof(token.c_str()));
        }
        else
        {
            std::cout << "Error" << std::endl;
            exit (-1);
        }
    }
    _result = (RPNStack.top());
}

RPN::~RPN() {

}

RPN::RPN(const RPN& src) {
    _result = src._result;
}

RPN& RPN::operator=(const RPN& rhs) {
    _result = rhs._result;
    return (*this);
}

// Getters
int RPN::getResult(void) {
    return (_result);
}