#include "ft_containers.hpp"

static void manual(void) {
    std::string input;

    std::cout << "***************************************************" << std::endl;
    std::cout << "** Welcome to the container project of hvan-hov! **" << std::endl;
    std::cout << "***************************************************" << std::endl << std::endl;
    std::cout << "Select one of the following tests to run: " << std::endl;
    std::cout << "- vectorAll" << std::endl;
    std::cout << "- vectorConstructor" << std::endl;
    std::cout << "- iteratorAll" << std::endl;
    std::cout << "- iteratorConstructor" << std::endl;
    /*
        More to be added here!
    */
    std::cout << "To exit, type \"exit\"" << std::endl;
    return ;
}

static void setOptions(std::map<std::string, void(*)()>& tests)
{
    tests["vectorAll"] = &vectorAll;
    tests["vectorConstructor"] = &vectorConstructor;
}

int main(void) {
    std::map<std::string, void(*)()>    tests;
    std::string                         input;

    manual();
    setOptions(tests);
    while (true)
    {
        std::cout << std::endl << "Select test: ";
        std::cin >> input;
        if (input == "exit") {
            std::cout << "Thanks for using the tester. Bye!" << std::endl;
            break ;
        }
        std::map<std::string, void(*)()>::iterator it = tests.find(input);
        if (it != tests.end()) {
            void (*selected_test)() = it->second;
            selected_test();
        }
        else {
            std::cout << "Invalid test name. Please try again or type \"exit\"" << std::endl;
        }
    }
    return (0);
}
