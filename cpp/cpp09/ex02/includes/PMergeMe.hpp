#ifndef PMergeMe_HPP
# define PMergeMe_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>

/*
    Vectors:
        - Continuous in memory
        - Random Access Iterators
        - Dynamically allocated

    List:
        - Non-continuous in memory
        - Bidirectional iterators
        - Dynamically allocated

*/

class PMergeMe {
    private:
        std::vector<int>    _vector;
        std::list<int>      _list;

    public:
        // Constructors
        PMergeMe();
        ~PMergeMe();
        PMergeMe(const PMergeMe& src);
        PMergeMe& operator=(const PMergeMe& rhs);

        // Methods
        void    mergeSortVector(void);
        void    mergeSortList(void);

        // Templates
        template <typename T>
        void    printContainer<T>(void) {
            for (T::const_iterator )
        }
};

#endif