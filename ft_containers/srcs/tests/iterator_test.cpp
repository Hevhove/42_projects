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

		std::cout << std::endl << "  [CODE]  " << std::endl;
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

		std::cout << std::endl << "  [CODE]  " << std::endl;
        std::cout << "    ft::vector<int>              ftTestVector(5, 42);" << std::endl;
        std::cout << "    ft::VectorIterator<int>      ftIterator(ftTestVector.begin() + 2);" << std::endl;
        std::cout << "    std::vector<int>             stdTestVector(5, 42);" << std::endl;
        std::cout << "    std::vector<int>::iterator   stdIterator(stdTestVector.begin() + 2);" << std::endl;

        std::vector<int>             stdTestVector(5, 42);
        ft::vector<int>              ftTestVector(5, 42);
		ft::VectorIterator<int>		ftIterator(ftTestVector.begin() + 2);
		std::vector<int>::iterator	stdIterator(stdTestVector.begin() + 2);

		std::cout << std::endl << "  [OUTPUT]  " << std::endl;
		std::cout << "    *ftIterator = " << *ftIterator << std::endl;
		std::cout << "    *stdIterator = " << *stdIterator << std::endl;
	}
}