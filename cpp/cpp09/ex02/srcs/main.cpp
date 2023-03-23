#include "PMergeMe.hpp"
#include <ctime>

bool isPositiveIntegerSequence(int argc, char** argv) {
    for (int i = 0; i < argc; i++)
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
    std::deque<int> list;

    // Assign sequences into them
    for (int i = 0; i < argc; i++)
        vector.push_back(atoi(argv[i]));
    for (int i = 0; i < argc; i++)
        list.push_back(atoi(argv[i]));
    PMergeMe<std::vector<int> > vectorClass;
    vectorClass.setContainer(vector);
    PMergeMe<std::deque<int> > listClass;
    listClass.setContainer(list);

    // Printing sequences
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Timing vector sort:
    clock_t vector_start = clock();
    vectorClass.mergeSort();
    clock_t vector_end = clock();
    double elapsedTimeVector = static_cast<double>(vector_end - vector_start) / CLOCKS_PER_SEC * 1000000;

    // Timing vector sort:
    clock_t list_start = clock();
    listClass.mergeSort();
    clock_t list_end = clock();
    double elapsedTimeList = static_cast<double>(list_end - list_start) / CLOCKS_PER_SEC * 1000000;

    // After (either will do)
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vectorClass.container().begin(); it != vectorClass.container().end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Report on timing
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << elapsedTimeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << elapsedTimeList << " us" << std::endl;


    return (0);
}