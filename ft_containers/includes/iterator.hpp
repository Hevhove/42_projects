#ifndef CLASS_VECTORITERATOR_HPP
#define CLASS_VECTORITERATOR_HPP

#include <cstddef>
#include <iterator>
#include <stdexcept>
/*
 * Vectors have random-access iterators to value_type.
 * Properties of random-access iterators are described here:
 * https://cplusplus.com/reference/iterator/RandomAccessIterator/
 */

namespace ft {
    template <typename T> class VectorIterator {
      public:
        // Typedefs
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
		typedef VectorIterator<T>				iterator;

        // Constructors
        VectorIterator() : _ptr(NULL){};
        VectorIterator(T* ptr) : _ptr(ptr){};
        virtual ~VectorIterator(){};
        VectorIterator(const VectorIterator& src) : _ptr(src._ptr){};
        VectorIterator& operator=(const VectorIterator& rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        // Comparison for equivalence
        bool operator==(const VectorIterator& rhs) {
            return (_ptr == rhs._ptr);
        };
        bool operator!=(const VectorIterator& rhs) {
            return (_ptr != rhs._ptr);
        };

        // Dereference
        reference operator*() const {return (*_ptr);};

        // Incrementation (Prefix, postfix)
        iterator&    operator++() {++_ptr;};
        iterator    operator++(int){
           iterator it(*this);
           ++_ptr;
           return (it);
        }

        // Decrementation (Prefix, postfix)
        iterator&    operator--() {--_ptr;};
        iterator    operator--(int){
           iterator it(*this);
           --_ptr;
           return (it);
        }

        // Arithmetic operators + and -
        iterator operator+(const difference_type& n) {
           iterator it(*this);
           it += n;
           return (it);
        }
        friend iterator operator+(const difference_type n, const iterator& it) { return (it + n); }
        iterator operator-(const difference_type& n) {
           iterator it(*this);
           it -= n;
           return (it);
        }
        friend iterator operator-(const difference_type n, const iterator& it) { return (it - n); }
        difference_type operator-(const iterator& rhs) const {
            return (_ptr - rhs._ptr);
        }
        // Comparison with inequality relational operators
        bool operator<(const VectorIterator& rhs) { return (_ptr < rhs._ptr); }
        bool operator<=(const VectorIterator& rhs) { return (_ptr <= rhs._ptr); }
        bool operator>(const VectorIterator& rhs) { return (_ptr > rhs._ptr); }
        bool operator>=(const VectorIterator& rhs) { return (_ptr >= rhs._ptr); }

        // Compound assignment operators
        iterator& operator+=(const difference_type& n){
            _ptr += n;
            return (*this);
        }
        iterator& operator-=(const difference_type& n){
            _ptr -= n;
            return (*this);
        }

        // Offset dereference
        reference operator[](const difference_type& n){ return (_ptr[n]); }
      private:
        T* _ptr;
    };

} // namespace ft

#endif // !CLASS_ITERATOR_HPP
