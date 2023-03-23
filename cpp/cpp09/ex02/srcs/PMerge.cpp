#include "${workspaceFolder/includes/PMerge.hpp"

// Constructors
PMergeMe::PMergeMe() {

}

PMergeMe::~PMergeMe() {

}

PMergeMe::PMergeMe(const PMergeMe& src) {

}

PMergeMe::PMergeMe& operator=(const PMergeMe& rhs) {

}

// Methods


// #include "PMergeMe.hpp"

// // Constructors
// template <typename T>
// PMergeMe<T>::PMergeMe() {
//     //
// }

// template <typename T>
// PMergeMe<T>::~PMergeMe() {

// }

// template <typename T>
// PMergeMe<T>::PMergeMe(const PMergeMe& src) {
//     _container = src.container;
// }

// template <typename T>
// PMergeMe<T>& PMergeMe<T>::operator=(const PMergeMe& rhs) {
//     _container = rhs.container;
//     return (*this);
// }

// // Getters
// template <typename T>
// T& PMergeMe<T>::container() {
//     return _container;
// }

// // Setters
// template <typename T>
// void        PMergeMe<T>::setContainer(const T& container) {
//     _container = container;
// }

// // Member Functions
// template <typename T>
// void    PMergeMe<T>::push_back(const typename T::value_type& value) {
//     _container.push_back(value);
// }

// template <typename T>
// void    PMergeMe<T>::mergeSort(void) {
//     if (_container.size <= 1)
//         return ;

//     // Split the container into two halves
//     T left, right;
//     typename T::iterator middle = _container.begin() + ((_container.size() + 1) / 2);
//     left.reserve(std::distance(_container.begin(), middle));
//     right.reserve(std::distance(middle, _container.end()));

//     // Copy the elements from the left and right halves to the new containers
//     typename T::const_iterator it = _container.begin();
//     for (;it != middle; ++it)
//         left.push_back(*it);
//     for (;it != _container.end(); ++it)
//         right.push_back(*it);

//     // Recursively sort the two halves
//     PMergeMe<T> leftPMergeMe, rightPMergeMe;
//     leftPMergeMe.setContainer(left);
//     rightPMergeMe.setContainer(right);
//     leftPMergeMe.mergeSort();
//     rightPMergeMe.mergeSort();

//     // Merge the two sorted halves
//     _container.clear();
//     _container.reserve(left.size() + right.size());
//     typename T::const_iterator leftIt = left.begin();
//     typename T::const_iterator rightIt = right.begin();

//     while (leftIt != left.end() && rightIt != right.end())
//     {
//         if (*leftIt < *rightIt)
//         {
//             _container.push_back(*leftIt);
//             ++leftIt;
//         }
//         else
//         {
//             _container.push_back(*rightIt);
//             ++rightIt;
//         }
//     }

//     // Append remaining elements
//     for (; leftIt != left.end(); leftIt) {
//         _container.push_back(*leftIt);
//     }
//     for (; rightIt != right.end(); ++rightIt) {
//         _container.push_back(*rightIt);
//     }
// }
