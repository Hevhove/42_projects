#include "ft_containers.hpp"

void    iteratorAll() {
	std::cout << "---- ITERATOR TESTS ----" << std::endl;
    iteratorConstructor();
    /*
        Add more ...
    */
}

void    iteratorConstructor() {
	// Default Iterator Constructor Tests
	{
		std::cout << std::endl << "- Default Iterator Constructor Tests:" << std::endl;

		std::cout << std::endl << "  [FUNCTION CALLS]  " << std::endl;
		std::cout << "    ft::VectorIterator<int>		ftIterator;" << std::endl;
		std::cout << "    std::vector<int>::iterator	stdIterator;" << std::endl;
		ft::VectorIterator<int>		ftIterator;
		std::vector<int>::iterator	stdIterator;

		std::cout << std::endl << "  [OUTPUT]  " << std::endl;
		std::cout << "    &ftIterator = " << &ftIterator << std::endl;
		std::cout << "    &stdIterator = " << &stdIterator << std::endl;
	}
	// Fill Iterator Constructor Tests
	{
		std::cout << std::endl << "- Fill Iterator Constructor Tests:" << std::endl;

		std::cout << std::endl << "  [FUNCTION CALLS]  " << std::endl;
		std::cout << "    ft::VectorIterator<int>		ftIterator();" << std::endl;
		std::cout << "    std::vector<int>::iterator	stdIterator();" << std::endl;
        std::vector<int>             testVector(5, 42);
		ft::VectorIterator<int>		ftIterator(testVector.begin() + 2);
		std::vector<int>::iterator	stdIterator(testVector.begin() + 2);

		std::cout << std::endl << "  [OUTPUT]  " << std::endl;
		std::cout << "    &ftIterator = " << &ftIterator << std::endl;
		std::cout << "    &stdIterator = " << &stdIterator << std::endl;
	}
}