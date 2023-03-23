#ifndef PMergeMe_HPP
# define PMergeMe_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>
# include <deque>

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

template<typename T>
class PMergeMe {
    private:
        T _container;

    public:
        // Constructors
        PMergeMe();
        ~PMergeMe();
        PMergeMe(const PMergeMe& src);
        PMergeMe& operator=(const PMergeMe& rhs);

        // Getters
        T& container();
        const T&    container() const;

        // Setters
        void        setContainer(const T& container);

        // Member Functions
        void        push_back(const typename T::value_type& value);
        void        mergeSort(void);
};

// Constructors
template <typename T>
PMergeMe<T>::PMergeMe() {
    //
}

template <typename T>
PMergeMe<T>::~PMergeMe() {

}

template <typename T>
PMergeMe<T>::PMergeMe(const PMergeMe& src) {
    _container = src.container;
}

template <typename T>
PMergeMe<T>& PMergeMe<T>::operator=(const PMergeMe& rhs) {
    _container = rhs.container;
    return (*this);
}

// Getters
template <typename T>
T& PMergeMe<T>::container() {
    return _container;
}

// Setters
template <typename T>
void        PMergeMe<T>::setContainer(const T& container) {
    _container = container;
}

// Member Functions
template <typename T>
void    PMergeMe<T>::push_back(const typename T::value_type& value) {
    _container.push_back(value);
}

template <typename T>
void    PMergeMe<T>::mergeSort(void) {
    if (_container.size() <= 1)
        return ;

    // Split the container into two halves
    T left, right;
    typename T::iterator middle = _container.begin() + static_cast<typename T::difference_type>((_container.size() + 1) / 2);

    // Copy the elements from the left and right halves to the new containers
    typename T::const_iterator it = _container.begin();
    for (;it != middle; ++it)
        left.push_back(*it);
    for (;it != _container.end(); ++it)
        right.push_back(*it);

    // Recursively sort the two halves
    PMergeMe<T> leftPMergeMe, rightPMergeMe;
    leftPMergeMe.setContainer(left);
    rightPMergeMe.setContainer(right);
    leftPMergeMe.mergeSort();
    rightPMergeMe.mergeSort();

    // Merge the two sorted halves
    _container.clear();
    typename T::const_iterator leftIt = left.begin();
    typename T::const_iterator rightIt = right.begin();
    std::less<typename T::const_iterator::value_type> lessThan;

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (lessThan(*leftIt,*rightIt))
        {
            _container.push_back(*leftIt);
            ++leftIt;
        }
        else
        {
            _container.push_back(*rightIt);
            ++rightIt;
        }
    }

    // Append remaining elements
    for (; leftIt != left.end(); ++leftIt) {
        _container.push_back(*leftIt);
    }
    for (; rightIt != right.end(); ++rightIt) {
        _container.push_back(*rightIt);
    }
}

#endif