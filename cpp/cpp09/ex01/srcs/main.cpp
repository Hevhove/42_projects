#include "RPN.hpp"

int main(int argc, char** argv) {
    // Check arguments
    if (argc != 2 || argv[1][0] == '\0')
    {
        std::cerr << "Error" << std::endl;
        return (-1);
    }

    std::string eqStr = argv[1];
    RPN RPNEquation(eqStr);

    std::cout << RPNEquation.getResult() << std::endl;

    return (0);
}