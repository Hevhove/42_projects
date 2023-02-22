#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP
/*
ft::enable_if
    Enable type if condition is met.
    The type T is enabled as member type enable_if::type if Cond is true.
    Otherwise, enable_if::type is not defined.
    This is useful to hide signatures on compile time when a particular condition is not met, since in this case, the member enable_if::type will not be defined and attempting to compile using it should fail.

ft::integral_constant
    Template designed to provide compile-time constants as types. It is used primarily for true_type and false_type
    We can provide it a value such as ft::integral_constant<int, 2> which will then make us an integral constant
    of that value where we have access to its:
        value: (static const int value = 2)
        value_type: int
        type: integral_constant<int, 2>
        conversion operator: allows us to make implicit casts between static const int and the struct integral_const<int, 2>

ft::is_integral
    See list of integral types on https://cplusplus.com/reference/type_traits/is_integral/
    List implemented below is not all inclusive of source above.
*/

namespace ft {
    template <bool Cond, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <class T, T val>
    struct integral_constant {
        static const T value = val;
        typedef T value_type;
        typedef integral_constant<T, val> type;
        operator value_type() const {
            return (value);
        }
    };

    typedef integral_constant<bool, false> false_type;
    typedef integral_constant<bool, true> true_type;

    template <class T>
    struct is_integral : false_type{} ;

    template <>
    struct is_integral<bool> : true_type {};

    template <>
    struct is_integral <char> : true_type {};

    template <>
    struct is_integral<unsigned char> : true_type {};

    template <>
    struct is_integral<short> : true_type {};

    template <>
    struct is_integral<unsigned short> : true_type {};

    template <>
    struct is_integral<int> : true_type {};

    template <>
    struct is_integral<unsigned int> : true_type {};

    template <>
    struct is_integral<unsigned long> : true_type {};

    template <>
    struct is_integral<long> : true_type {};

    template <>
    struct is_integral<long long> : true_type {};

    template <>
    struct is_integral<unsigned long long> : true_type {};

} // namespace ft

#endif