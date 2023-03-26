#include "PMergeMe.hpp"
#include <ctime>

bool isPositiveIntegerSequence(int argc, char** argv) {
    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);
        if (num <= 0)
            return false;
    }
    return (true);
}

int main(int argc, char** argv) {
    // Check inputs
    if (argc < 2 || !isPositiveIntegerSequence(argc, argv))
    {
        std::cout << "Error: please provide a sequence of positive integers" << std::endl;
    }

    // Create container classes
    std::vector<int> vector;
    std::deque<int> deque;

    // Assign sequences into them
    for (int i = 1; i < argc; i++)
        vector.push_back(atoi(argv[i]));
    for (int i = 1; i < argc; i++)
        deque.push_back(atoi(argv[i]));
    PMergeMe SortingTest(vector, deque);

    // Printing sequences
    std::cout << "Before: ";
    SortingTest.printVector();

    // Timing vector sort:
    clock_t vector_start = clock();
    SortingTest.mergeSortPMergeVector();
    clock_t vector_end = clock();
    double elapsedTimeVector = static_cast<double>(vector_end - vector_start) / CLOCKS_PER_SEC * 1000000;

    // Timing list sort:
    clock_t deque_start = clock();
    SortingTest.mergeSortPMergeDeque();
    clock_t deque_end = clock();
    double elapsedTimeList = static_cast<double>(deque_end - deque_start) / CLOCKS_PER_SEC * 1000000;

    // After (either will do)
    std::cout << "After: ";
    SortingTest.printVector();

    // Report on timing
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << elapsedTimeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << elapsedTimeList << " us" << std::endl;

    return (0);
}