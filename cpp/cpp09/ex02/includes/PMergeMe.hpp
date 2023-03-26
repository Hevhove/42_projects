#ifndef PMergeMe_HPP
# define PMergeMe_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <deque>

/*
    Vectors:
        - Continuous in memory
        - Random Access Iterators
        - Dynamically allocated

    deque:
        - Non-continuous in memory
        - Bidirectional iterators
        - Dynamically allocated

*/

class PMergeMe {
    private:
        std::vector<int>    _vector;
        std::deque<int>     _deque;

    public:
        // Constructors
        PMergeMe();
        PMergeMe(std::vector<int>& vector, std::deque<int>& deque);
        ~PMergeMe();
        PMergeMe(const PMergeMe& src);
        PMergeMe& operator=(const PMergeMe& rhs);

        // Methods
        void    mergeSortPMergeVector(void);
        void    mergeSortPMergeDeque(void);
        void    printVector(void);
        void    printDeque(void);
};

// Helper prototypes
void mergeSortVector(std::vector<int>& vec);
void mergeSortDeque(std::deque<int>& vec);

#endif