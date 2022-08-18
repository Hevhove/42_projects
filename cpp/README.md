## C++ Piscine Notes

### Namespaces
Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them the *namespace* scope. Namespaces only appear at global scope. A common example is the 'std' namespace, which has certain objects defined such as `std::cout` and `std::cin`, which are the standard out and standard in. The operator `::` is known in C++ as the resolution operator. To use the stdin and stdout, we still have to define the header `#include <iostream>`.

So what is the difference between headers and namespaces? 

Header files contain the declaration of functions. Usually when using a function in a `.c` file, we must first declare the prototype, so that the compiler knows that we have defined it somewhere in our source code. The actual implementation of these functions however can be either in our own source code or in shared libraries. For example, for printf, the implementation is defined within `libc.so` which are then linked into the final executable. 

Namespaces on the other hand do not exist as a file system object. Rather they are a way of telling the compiler that certain things are within that namespace. They typically group interfaces (functions, classes/structs, types, global variables) of similar (but not necessarily independent) items. For instance `std` namespace in C++ contains all of the Standard Library Functions and classes. 

So, coming back to our `std::cout` and `std::cin` example, these are both objects defined within the `std` namespace. They would be global objects, but in C++ we contain them to a namespace, freeing up the names cout and cin for local scope (avoiding name clashes) while also making for prettier code. In C, programmers must be careful when adding new names to its standard library. To make use of the global objects `std::cout` and `std::cin` we do still need to include a header file, which contains the class definition of input and output streams (which `cout` and `cin` are instances of) + all the other prototypes they might need access to.

### Stdio Streams
In C++ we use the stdio streams `std::cout`, `std::cin`, `std::cerr` and `std::clog` to input and output to the user interface (terminal). The operators `>>` and `<<` are overloaded for the objects of type iostream so that we can input/output to certain buffers. To end a newline, we can use `<< std::endl`, which serves the same purpose as `\n`, but a key difference is that endl causes a flushing of the output buffer everytime it is called, while `\n` does not. 

In C++, anything that is outputted is first queued into an output buffer and then written to the device. In large programs, it can be efficient to use a simple `\n` to improve performace because not buffer flush happens. `std::cout << std::endl` is the same as `std::cout << '\n' << std::flush`.

After using `std::cin` it is wise to clear the input buffer to accept the next input from the user. If a user enters to `std::cin` input, this input is always followed by the `\n` character. Unfortunately, `std::cin`, is only going to take the input BEFORE the newline character, and store it into the variable defined for entry. The newline gets left behind in the input buffer. Consequent calls to functions such as `cin.getline(buff, size)` will then just find the newline character and halt there, giving us empty input from getline. We can use the ignore function to clear the input buffer: `cin.ignore(1, '\n'`). Ignore will ignore up to 1 amount of chars on the input buffer or until it encounters the first newline. A good solution is to provide the largest amount of characters that we can provide on the screen: `cin.ignore(numeric_limits<streamsize>::max(), '\n');`. This way, we always clear until we find the first newline.

### Classes and Instances
Classes are like templates. Your dad's old Renault Clio is an "instance" of the template (or class) a Renault Clio car. Classes can be linked together into hierarchical orders. For example, the Renault Clio is a subclass of Renault cars, while a Renault Car is a subclass of a Car. You could also logically divide cars into sedans, SUVs, ...

Here is an example of a class in C++:

    class Sample {
        private:
            int     x;

        public:
            Sample(); // Constructor
            ~Sample(); // Destructor
    };

Within a class, we can define member variables and member functions which can be either public or private. These can be accessed with the `.` operator on the instance of a class. Constructors are functions that are called when an object is instantiated while destructors are called when an object goes out of scope. Linux and Mac have slightly different behaviours for destructing order.

In terms of structuring files, we put class templates inside of `ClassName.hpp` files while we put the member function implementation inside of `ClassName.cpp` files.

### C++ Access Specifiers (Private, Public, Protected)
Public and private are access specifiers, which define how members (attributes and methods) of a class can be accessed. Public members can be accessed and modified from outside the code. 

In C++, there are three access specifiers:

1. public - members are accessible from outside the class
2. private - members cannot be accessed (or viewed) from outside the class
3. protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

The below code example demonstrates what is allowed and what not:

```
 class MyClass {
  public:    // Public access specifier
    int x;   // Public attribute
  private:   // Private access specifier
    int y;   // Private attribute
};

int main() {
  MyClass myObj;
  myObj.x = 25;  // Allowed (public)
  myObj.y = 50;  // Not allowed (private)
  return 0;
}
```

### 'this' keyword

The `this` keyword is used to refer to the current instance of the class. `this` is a pointer that points to the class instance itself. We can use this to for example change variable contents inside of the constructor such as:

```
SampleClass::SampleClass(void) {
    this->foo = 42;
}
```

In the above example, we immediately set the foo variable to 42 when instantiated. We can also use the this keyword to call a function such as `this->bar()` which will immediately call the function defined in the instantiated object. Note that it is not possible to call a function in C in this manner.

### Initialization List
We can use initialization lists to clean up variable intializations inside of a constructor. The alternative is to set variable with the `this` keyword.

Option 1:
```
SampleClass::SampleClass(char p1, int p2, float p3) {
    this->a1 = p1;
    this->a2 = p2;
    this->a3 = p3;
}
```

Option 2:
```
SampleClass::SampleClass(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {
    // Code
}
```

### Const

Variables and functions can be made constant which means we cannot assign values into them. The below block shows 3 examples of const usage:

```
class Sample {
    float const pi; // A constant variable -> can't be changed after initialization!
    int         qd;

    Sample( float const f); // a constant parameter
    ~Sample(void);

    void    bar(void) const; // a constant function -> this means that this function will never modify the current instance of the class. Common in viewing functions.
}
```

### Class vs Struct
Structs and Classes are the same in C++ except for in a class by default members are private while in structs they are public by default

### Accessors
To give users a way to read/write to private attributes, the developer can choose to implement accessor functions (getters). Using such functions, we can provide read access of private variables outside of the class, or we can for example put constraints to the user on how a variable is set.

### Non-member attributes and functions (AKA class variables and class functions)
The `static` keyword inside of a class is used to create methods that can access information about all of the instances of the class. For example, when invoked on an instance of type Car, a function `static int getCarInst(void)` could return the total number of instantiated cars. It is never possible to call this `this` keyword inside a non-member function because the function does not apply to an instance. 

### Pointers to members
If we want to generate a pointer to a member of a class, we have to use a special syntax when declaring this pointer:
```
int     Sample::*p = NULL;
void    (Sample::*f)(void) const;
```

In the above example, we have a pointer p that has the address of an integer which is a member of the Sample class. Later we could assign it for example with `p = &Sample::foo;` where p is now the address of the member variable foo of the class Sample.

The problem is now, that every instance has a different memory address, so what is the address of the pointer to member `p`? In reality, we can only call it by using `instance.*p`, but never by using `*p`. Alternatively, if we are dealing with a pointer to an object, we can use `instanceptr->*p` to access the value.

For the member functions, similarly, we need to define the function `f` as belonging to the class: `void    (Sample::*f)(void) const;`. After this declaration we can work with the function in the following way to call it:
```
f = &Sample::bar; // Assign an address into f

(instance.*f)(); // Calling the member function f onto the instance
(instanceptr->*f)(); // Calling the member function onto a pointer to the instance
```

### New and Delete keywords
In C, we use malloc() and free(). When we want to allocate ints, floats, doubles, this is no problem. But when working with objects, this isn't the best, because it does not call the constructor, neither will it call the destructor of an object. 

The keyword `new` will call the constructor of an object and `delete` will call its destructor before freeing memory.

```
Student     bob = Student("bfubar");        // Student object on the stack
Student*    jim = new Student("jfubar");    // Student object on the heap

delete jim // jim is destroyed
return (0); // bob is destroyed
```

If we have an array of objects

```
int main (void)
{
    Student* students = new Student[42]; // we allocate memory for 42 students on the heap here.
    // Do some stuff
    delete[] students; // we can delete all student objects in one go by using the bracket notation delete[] here.
}
```

### References
References in C++ can be looked at as an alias. However a more correct definition would be that a reference is a pointer that is constant and always dereferenced and never NULL.

```
int main()
{
    int noBalls = 42;

    int* ballsPtr = &noBalls; // this initializes a pointer to the address of noBalls
    int& ballsRef = noBalls; // this initializes a reference to noBalls 

    int& ballsRef2; // THIS IS WRONG -> we cannot create uninitialized references.
}
```

C++ added the so-called reference variables (or references in short). A reference is an alias, or an alternate name to an existing variable. For example, suppose you make peter a reference (alias) to paul, you can refer to the person as either peter or paul.

The main use of references is acting as function formal parameters to support pass-by-reference. In an reference variable is passed into a function, the function works on the original copy (instead of a clone copy in pass-by-value). Changes inside the function are reflected outside the function.

A reference is similar to a pointer. In many cases, a reference can be used as an alternative to pointer, in particular, for the function parameter.

### Filestreams
Besides iostreams, there exist also filestreams (#include <fstream>). We can open a filestream with name 'numbers' in the following manner: `std::ifstream  ifs("numbers")`. We can then read from it: `ifs >> dst >> dst2`. Finally, we should close an fstream: `ifs.close()`.

Similarly, there are output filestreams which we can call using `std::ofstream ofs("test.out")`.

### Adhoc Polymorphism

