# Ft_Containers

## Subject
Implement the following containers and turn in the necessary <container>.hpp files with
a Makefile:
• vector

You don’t have to do the vector<bool> specialization.
• map
• stack

It will use your vector class as default underlying container. But it must still be compatible with other containers, the STL ones included. You can pass this assignment without the stack (80/100). But if you want to do the bonus part, you have to implement the 3 mandatory containers: vector, map and stack.

You also have to implement:
• std::iterator_traits
• std::reverse_iterator
• std::enable_if (Yes, it is C++11 but you will be able to implement it in a C++98 manner.)
This is asked so you can discover SFINAE.
• std::is_integral
• std::equal and/or std::lexicographical_compare
• std::pair
• std::make_pair

### Requirements
• The namespace must be ft.
• Each inner data structure used in your containers must be logical and justified (this
means using a simple array for map is not ok).
• You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function or
variable must be justified.
• All the member functions, non-member functions and overloads of the standard
containers are expected.
• You must follow the original naming. Take care of details.
• If the container has an iterator system, you must implement it.
• You must use std::allocator.
• For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.
• Of course, for the implementation of std::map::value_compare, the keyword
friend is allowed.
You can use https://www.cplusplus.com/
and https://cppreference.com/ as references.

### Testing
• You must also provide tests, at least a main.cpp, for your defense. You have to go
further than the main given as example!
• You must produce two binaries that run the same tests: one with your containers
only, and the other one with the STL containers.
• Compare outputs and performance / timing (your containers can be up to 20
times slower).
• Test your containers with: ft::<container>.

# Project Notes
## Templates
A template are a bit similar to Macros and are immensely powerful in C++. A template basically allows you to define a template that will be compiled by your usage. You can get the compiler to write code for you based on a set of rules that you give it.

When you write a function that uses a template, this is a blueprintfor the compiler to write more functions just like it with different types. The compiler will only write the functions for us that are later used in our code. For example, if we define a template, but only call the templated function with <int> and <long>, the compiler will only write the functions for int and long, not for other numerical types.

Example:
```
template <typename T>   // alternative: template <class T>
void print(T value)     // T is a type of wildcard that could be any type
{
    std::cout << value << std::endl;
}

int main(void)
{
    print(5.5);       // implicit instantiation to float
    print<int>(5);    // explicit instantiation to int -> we prefer this!
}
```

Templates only get created when the function is called. For example, if we would write a syntax error inside of a template but not have a call to the template, the compiler will not actually complain. Only when the function is called, does the compiler create a function out of the template using that particular type. This comes in handy as well, where we could for example create a template that only works on numerical values, but not on chars. If the compiler would syntactically check for every type in the template, this would be a lot of work for something that maybe would not get called.

Templates are by no means just limited to types and not limited to functions either. You can create entire classes based on templates and this is alot of what the STL is in C++, just completely using templates. 

Let's use a template for a class now instead of a function!
```
template<typename T, int N> // We can use more than just types, also a simple datatype will work!
class Array 
{
  private:
    T m_Array[N];
  public:
    int getSize() const {return N;}
};

int main(void)
{
  Array<int, 5> array;
  
  std::cout << array.getSize() << std::endl;
  return (0);
}
```

In the above example we showcase we are not limited to a typename but it can be any datatype as well. It's common for the above approach to be called metaprogramming because we aren't really programming anymore to make changes in the runtime of the program, rather we are programming what the compiler will create at compile-time. In the end we are letting the compiler write code for us based on a set of rules we define in a template.

The downside is that templates can become extremely complex and can therefore be shunned sometimes. There are programs available to display the actual code created by templates. 

## Vectors
Vectors are a bit of a misnomer in C++, they are more like ArrayLists. Vectors are resizeable arrays in C++. While Arrays are set with a particular length at their initialization, we can keep on resizing vectors by adding elements into it. This means we can start off not knowing how many elements our vector will contain.

Initially, a vector starts off with a certain size, but once a certain threshold is reached, allocates a new array bigger in size and transfers the items there. Note that vectors are in fact stored continuously in memory in c++ (so they are not linked lists!).

## Rvalues and lvalues
Lvalues are often called locator values. This is because they have some kind of location.

```
int main(void)
{
  int i = 10;      // i (lvalue)has a location in memory, 10 (rvalue) does not.
  int a = i;       // here we are setting an lvalue equal to another lvalue.
  getValue() = 5;  // this does not compile, because the left side is an rvalue
  getValue2() = 7; // this does work because we are using an lvalue reference!
  setValue(i);     // in this case, 
  setValue(10);    // rvalue will be used to create an lvalue in scope of setValue
  setValue2(10);   // Doesnt work! Can only take lvalue-reference of an l-value!

  int& j = 10;       // invalid!
  const int& j = 10; // when we add const, this is allowed
                     // this is a special rule that is a workaround, the compiler 
                     // does not actually work like this. 
  setValue3(10);     // now this is valid! a const reference lvalue can accept
                     // both lvalues and rvalues!
}

int getValue()
{
  return 10; // this is also an rvalue when called in main!
}

int& getValue2()
{
  static int value = 10;
  return value;
}

void  setValue(int value)
{

}

void  setValue2(int& value)
{

}

void  setValue3(const int& value)
{

}
```

Let's look at another example with strings!
```
void printName(std::string& name)
{
  std::cout << name << std::endl;
}

void printName2(const std::string& name)
{
  std::cout << name << std::endl;
}

void printName3(std::string&& name)
{
  std::cout << name << std::endl;
}

int main(void)
{
  std::string firstName = "Jack"; // lvalue = rvalue
  std::string lastName = "Jones"; // lvalue = rvalue
  std::string fullName = firstName + lastName; // lvalue = rvalue!
  
  // 2 variables added together create an r-value! The resulting expression is not assigned into a memory space itself, rather into fullname which is an lvalue.
  printName(fullName); // works!
  printName(firstName + lastName) // doesn't work with string&
  printName2(firstName + lastName) // works, because of const!

  // r-value references
  printName3(fullName); // does not work!
  printName3(firstName + lastName) // works due to rvalue reference
} 
```
## Iterators 



# Resources

- [CPP](https://www.learncpp.com/)
- [Vectors](https://en.cppreference.com/w/cpp/container/vector)
- [SFINAE](https://www.cppstories.com/2016/02/notes-on-c-sfinae/)
- [Tiago's awesome github](https://github.com/Olbrien/42Lisboa-lvl_5_ft_containers/tree/main/ft_containers)
