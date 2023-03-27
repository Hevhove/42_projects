#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN {
    private:
        int             _result;

    public:
        // Constructors
        RPN();
        RPN(std::string eqStr);
        ~RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& rhs);

        // Getters
        int getResult(void);
};

#endif