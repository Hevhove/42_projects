#include <iostream>

class Base {
    private:
        int dom;
    public:
        typedef int lol;
};


int main(void) {
    Base::lol lol = 3;

    std::cout << std::is_arithmetic<long>::value << std::endl; 
}
