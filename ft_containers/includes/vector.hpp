#ifndef CONTAINER_VECTOR_HPP
#define CONTAINER_VECTOR_HPP

// Libraries
#include "iterator.hpp"
#include "enable_if.hpp"
#include <iostream>

namespace ft {

    template <typename T, typename Allocator = std::allocator<T> >
    class vector {
      public:
        // Typedefs
        typedef T                                        value_type;
        typedef Allocator                                allocator_type;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename ft::VectorIterator<T>           iterator;
        typedef typename ft::VectorIterator<const T>     const_iterator;

        // Constructors
        explicit vector(const Allocator& alloc = Allocator())
            : _alloc(alloc), _size(0), _capacity(0){};
        explicit vector(size_type count, const value_type& value = value_type(),
                        const Allocator& alloc = Allocator())
            : _alloc(alloc), _size(count), _capacity(count) {
            if (count > max_size())
                throw std::length_error(
                    "input value assigned to vector is too large");
            _ptr = _alloc.allocate(count);
            for (size_type i = 0; i < count; i++)
                _alloc.construct(_ptr + i, value);
        };
        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type& alloc = allocator_type(),
               typename enable_if<!is_integral<InputIterator>::value>::type * = 0)
            : _alloc(alloc), _size(last - first), _capacity(last - first) {
            size_type size = last - first;
            if (size > max_size())
                throw std::length_error(
                    "input value assigned to vector is too large");
            _ptr = _alloc.allocate(size);
            for (size_type i = 0; first != last; first++, i++)
                _alloc.construct(_ptr + i, *first);
        };
        ~vector() {
            clear();
            if (_capacity > 0)
                _alloc.deallocate(_ptr, _capacity);
            _capacity = 0;
        };
        vector(const vector& src) { (void)src; };
        vector& operator=(const vector& rhs) {
            if (this != &rhs) {
                // todo: assign function
            }
        };

        // Iterators
        iterator       begin() { return (iterator(_ptr)); }
        const_iterator begin() const { return (const_iterator(_ptr)); }
        iterator       end() { return (iterator(_ptr + _size)); }
        const_iterator end() const { return (const_iterator(_ptr + _size)); }

        // Methods : Capacity
        size_type size() const { return (_size); };
        size_type max_size() const { return (_alloc.max_size()); };
        void      resize(size_type n, value_type val = value_type()) {
            if (n > _capacity)
                reserve(n);
            if (n > _size) {
                for (size_type i = _size; i < n; i++)
                    push_back(val);
            } else if (n < _size) {
                for (size_type i = n; i < _size; i++)
                    _alloc.destroy(_ptr + i);
                _size = n;
            }
        };
        size_type capacity() const { return (_capacity); }
        bool      empty() const { return (_size == 0); }
        void      reserve(size_type n) {
            /*
             *	Request a the vector capacity to be at least n
             *	If n is greater than the current vector capacity,
             *	the function causes the container to reallocate its
             *	storage increasing its capacity to n (or greater).
             */
            if (n <= _capacity)
                return;
            pointer tmp = _alloc.allocate(
                n); // ask the allocator to allocate us a memory block of size n
            for (size_type i = 0; i < _size;
                 i++) // call construct at every pointer location that was
                      // allocated with _alloc.allocate(n)
                _alloc.construct(tmp + i, *(_ptr + i));
            size_type tmp_size = _size;
            clear();
            _alloc.deallocate(_ptr, _capacity);
            _ptr = tmp;
            _size = tmp_size;
            _capacity = n;
        }

        // Methods: Modifiers
        void clear() {
            /*
             *	Removes all elements from the vector (which are destroyed),
             *leaving the container with _size of 0.
             */
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_ptr + i);
            _size = 0;
        }

      private:
        allocator_type _alloc;
        size_type      _size;
        size_type      _capacity;
        pointer        _ptr;
    };
}; // namespace ft
#endif
