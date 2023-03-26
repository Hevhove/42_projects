#include "PMergeMe.hpp"

// Constructors
PMergeMe::PMergeMe() {

}

PMergeMe::PMergeMe(std::vector<int>& vector, std::deque<int>& deque) {
    _vector = vector;
    _deque = deque;
}

PMergeMe::~PMergeMe() {

}

PMergeMe::PMergeMe(const PMergeMe& src) {
    _vector = src._vector;
    _deque = src._deque;
}

PMergeMe& PMergeMe::operator=(const PMergeMe& rhs) {
    _vector = rhs._vector;
    _deque = rhs._deque;
    return (*this);
}

// Helper functions
void mergeDeque(std::deque<int>& deq, int left, int middle, int right) {
    // Make space for the amount of elements needed in the temporary vector
    std::deque<int> temp(right - left + 1);

    int i = left;           // index of the first element in the left subvector
    int j = middle + 1;     // index of the first element in the right subvector
    int k = 0;              // index of the first element in the temporary vector

    // merge the 2 subvectors together
    while (i <= middle && j <= right) {
        if (deq[i] < deq[j]) {
            temp[k++] = deq[i++];
        } else {
            temp[k++] = deq[j++];
        }
    }

    // copy remaining elements from left subvector
    while (i <= middle) {
        temp[k++] = deq[i++];
    }

    // copy remaining elements from right subvector
    while (j <= right) {
        temp[k++] = deq[j++];
    }

    // copy sorted elements from the temporary vector into the original vector
    for (i = left; i <= right; ++i) {
        deq[i] = temp[i - left];
    }
}

// Deque
void mergeSortHelperDeque(std::deque<int>& deq, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSortHelperDeque(deq, left, middle);
        mergeSortHelperDeque(deq, middle + 1, right);
        mergeDeque(deq, left, middle, right);
    }
}

void mergeSortDeque(std::deque<int>& deq) {
    mergeSortHelperDeque(deq, 0, deq.size() - 1);
}

void merge(std::vector<int>& vec, int left, int middle, int right) {
    // Make space for the amount of elements needed in the temporary vector
    std::vector<int> temp(right - left + 1);

    int i = left;           // index of the first element in the left subvector
    int j = middle + 1;     // index of the first element in the right subvector
    int k = 0;              // index of the first element in the temporary vector

    // merge the 2 subvectors together
    while (i <= middle && j <= right) {
        if (vec[i] < vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    // copy remaining elements from left subvector
    while (i <= middle) {
        temp[k++] = vec[i++];
    }

    // copy remaining elements from right subvector
    while (j <= right) {
        temp[k++] = vec[j++];
    }

    // copy sorted elements from the temporary vector into the original vector
    for (i = left; i <= right; ++i) {
        vec[i] = temp[i - left];
    }
}

void mergeSortHelper(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSortHelper(vec, left, middle);
        mergeSortHelper(vec, middle + 1, right);
        merge(vec, left, middle, right);
    }
}

void mergeSortVector(std::vector<int>& vec) {
    mergeSortHelper(vec, 0, vec.size() - 1);
}

// Methods
void    PMergeMe::printVector(void) {
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PMergeMe::printDeque(void) {
    for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PMergeMe::mergeSortPMergeVector(void) {
    mergeSortVector(_vector);
}

void PMergeMe::mergeSortPMergeDeque(void) {
    mergeSortDeque(_deque);
}
