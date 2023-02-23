#include "ft_containers.hpp"

void vectorAll() {
	std::cout << "---- VECTOR TESTS ----" << std::endl;
    vectorConstructor();
    /*
        Add more ...
    */
}

void vectorConstructor() {
	// Default Vector Constructor Tests
	{
		std::cout << std::endl << "- Default Vector Constructor Tests:" << std::endl;

		std::cout << std::endl << "  [CODE]  " << std::endl;
		std::cout << "    ft::vector<int>			ftVector;" << std::endl;
		std::cout << "    std::vector<int>		stdVector;" << std::endl;
		ft::vector<int>		ftVector;
		std::vector<int>	stdVector;

		std::cout << std::endl << "  [OUTPUT]  " << std::endl;
		std::cout << "    &ftVector = " << &ftVector << std::endl;
		std::cout << "    stdVector._size = " << stdVector.size() << std::endl;
		std::cout << "    ftVector._capacity = " << ftVector.capacity() << std::endl;
		std::cout << "    stdVector._capacity = " << stdVector.capacity() << std::endl;
	}
	// Fill Vector Constructor Tests
	{
		std::cout << std::endl << "- Fill Vector Constructor Tests:" << std::endl;

		std::cout << std::endl << "  [CODE]  " << std::endl;
		std::cout << "    ft::vector<int>   ftVector(10);" << std::endl;
		std::cout << "    std::vector<int>  stdVector(10);" << std::endl;
		ft::vector<int>		ftVector(10);
		std::vector<int>	stdVector(10);

		std::cout << std::endl << "  [OUTPUT]  " << std::endl;
		std::cout << "    ftVector._size = " << ftVector.size() << std::endl;
		std::cout << "    stdVector._size = " << stdVector.size() << std::endl;
		std::cout << "    ftVector._capacity = " << ftVector.capacity() << std::endl;
		std::cout << "    stdVector._capacity = " << stdVector.capacity() << std::endl;
	}
	// Range Vector Constructor Tests
	{
		std::cout << std::endl << "- Range Vector Constructor Tests:" << std::endl;

		std::cout << std::endl << "  [FT CODE]  " << std::endl;
        std:: cout << "ft::vector<int>            ftVector(5, 42);" << std::endl;
        std:: cout << "ft::vector<int>::iterator  ftFirst = ftVector.begin();" << std::endl;
        std:: cout << "ft::vector<int>::iterator  ftLast = ftVector.end();" << std::endl;
        std:: cout << "ft::vector<int>            newFtVector(ftFirst, ftLast);" << std::endl;
        std::cout << "std::cout << \"Vector contents: \"; " << std::endl;
        std::cout << "for (; ftFirst!= ftLast; ftFirst++) " << std::endl;
        std::cout << "    std::cout << *ftFirst; " << std::endl;
        std::cout << "std::cout << std::endl; " << std::endl;

		std::cout << std::endl << "  [FT OUTPUT]  " << std::endl;
        ft::vector<int>            ftVector(5, 42);
        ft::vector<int>::iterator  ftFirst = ftVector.begin();
        ft::vector<int>::iterator  ftLast = ftVector.end();
        ft::vector<int>            newFtVector(ftFirst, ftLast);
        std::cout << "Vector contents: ";
        for (; ftFirst!= ftLast; ftFirst++)
            std::cout << " " << *ftFirst;
        std::cout << std::endl << std::endl;

		std::cout << std::endl << "  [STD CODE]  " << std::endl;
        std:: cout << "std::vector<int>            stdVector(5, 42);" << std::endl;
        std:: cout << "std::vector<int>::iterator  stdFirst = stdVector.begin();" << std::endl;
        std:: cout << "std::vector<int>::iterator  stdLast = stdVector.end();" << std::endl;
        std:: cout << "std::vector<int>            newStdVector(stdFirst, stdLast);" << std::endl;
        std::cout << "std::cout << \"Vector contents: \"; " << std::endl;
        std::cout << "for (; stdFirst!= stdLast; stdFirst++) " << std::endl;
        std::cout << "    std::cout << *stdFirst; " << std::endl;
        std::cout << "std::cout << std::endl; " << std::endl;

		std::cout << std::endl << "  [STD OUTPUT]  " << std::endl;
        std::vector<int>           stdVector(5, 42);
        std::vector<int>::iterator stdFirst = stdVector.begin();
        std::vector<int>::iterator stdLast = stdVector.end();
        std::vector<int>            newStdVector(stdFirst, stdLast);
        std::cout << "Vector contents: ";
        for (; stdFirst!= stdLast; stdFirst++)
            std::cout << " " << *stdFirst;
        std::cout << std::endl;
	}
}