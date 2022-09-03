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
Adhoc Polymorphism means the ability to take on many forms. In terms of functions in C++, this means we can define a function with a particular name, but change for example the type of the arguments `func1(float f)` vs `func1(int i)`, without any problem. This is also known as function overloading.

### Canonical Form
The canonical form of a class means a class has explicitly defined 4 constructors:

1. Default constructor with empty arguments or all arguments with a default value `Class();`
2. Default destructor `~Class()`
3. Copy constructor `Class(Class const &src)`
4. Copy assignment constructor `Class& operator=(Class const & rhs)`

### Const Keyword Usage
[Interesting Article on Const Usage](https://www.cprogramming.com/tutorial/const_correctness.html). Another quick review on const here! Const allows us to define whether or not a specific variable is modifiable. It can be used to prevent modifications to variables, and const pointers and const references prevent changing the data pointed to.

This gives us the ability to document our code better and prevent coding mistakes. Users of a function with a const argument do not need to worry about modifying the underlying object. Similarly, we use const in getter functions and other similar functions to make sure nothing gets changed.

#### Const variable
For constant variables, the positioning of const does not make a difference:
`int const x = 5;` is equivalent to `const int x = 5;`.

Note that we have to make x const in the declaration and cannot do it later.

#### Const pointers
References are pretty natural. By definition, they cannot change the data they point to. When making a reference const, you're only making the data referred to const. Pointers on the other hand, have 2 ways to be used: you can change the data pointed to or change the pointer itself. Because of this, there are 2 ways of declaring a const pointer. One that prevents you from changing what is pointed to, and one that prevents you from changing the data pointed to.

Pointer to constant data:
`const int *p_int` -> *p_int is a const int. The pointer may be changeable, but you cannot change what p_int points to.

Constant pointer:
`int x`
`int * const p_int = &x` -> The address stored in the pointer is now const, the const comes after the * symbol. Note that we had to declare what it points to immediately, because we cannot change the pointer later! For example, the address would be 0x000FA930A, and would have to remain so. The data at this memory address can be changed however. Generally, the first definition (pointer to const data) is used as "const pointer" in terminology.

#### Const functions
Of course, in classes we can also decide to make functions const by declaring const behind the function prototype. Once a variable is const, it cannot be assigned a non-const reference throughout the program, which is necessary to enforce const-ness. Const functions are the only functions that can be called on a const object. Non-const functions are not allowed. 

Note that just because a function is declared const that doesn't prohibit non-const functions from using it; the rule is this:  
1. Const functions can always be called. 
2. Non-const functions can only be called by non-const objects

### Inheritance
In C++, classes can inherit behaviour (variables and methods) from parent classes. A Car for example, could have as a parent class "Vehicle". The notation is as follows:

```
class Vehicle {
    private:
        int     wheels;
    public:
        void    drive(void);
}

class Truck : public Vehicle {
    private: 
        int     load_capacity;
    public:
        void    emergency_brake();
}
```

In the above example, the Truck inherits publicly from the vehicle class. Meaning, it has access to all of the public members of the class Vehicle. Here are all the modes of inheritance in C++:

1. Public inheritance: makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.
2. Protected inheritance: makes the public and protected members of the base class protected in the derived class.
3. Private inheritance: makes the public and protected members of the base class private in the derived class.

Additionally, we can define protected members of a class, meaning they will only be accessable by children of the parent, but otherwise private.

When instantiating a child, the parent class will be instantiated before it, so its constructor will be called before the constructor of the child class. But upon going out of scope, the child is destructed first.

#### Solving the Diamond Problem with Virtual Inheritance
Multiple inheritance in C++ can often lead to problems. [link to resource](https://www.cprogramming.com/tutorial/virtual_inheritance.html) shows us how 2 children can inherit from the same parent class, but then a subclass of the children could inherit from both child classes, creating a diamond inheritance. If the grandchild now wants to call a method defined in its grandparent, this call is ambiguous. The grandparent class will be duplicated inside of the grandchild class. We can solve this using virtual inheritance. 

```
class transmitter: public virtual storable 
{
        public:
        void read();
        ...
} 
 
class receiver: public virtual storable
{
        public:
        void read();
        ...
} 
```

When using virtual inheritance, we guarantee to only receive a single instance of the common base class. This instance of the base class, is then shared by both children. 

### Virtual Functions
If we have a parent and a child class, see [link](https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c), and both the parent and child class have the implementation of a function `foo()`, then we need the keyword `virtual` if we want to call the method `foo` from the subclass instead of from the superclass. For example, if we would have Animal and Cat, calling foo(cat) gives us the correct behaviour but if we nest foo() inside of another function, we get the foo() behaviour from the parent class. To prevent this we can use the virtual keyword.

### Virtual Destructors
Virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class:
```
class Base 
{
    // some virtual methods
};

class Derived : public Base
{
    ~Derived()
    {
        // Do some important cleanup
    }
};
```
Here, you'll notice that I didn't declare Base's destructor to be virtual. Now, let's have a look at the following snippet:
```
Base *b = new Derived();
// use b
delete b; // Here's the problem!
```
Since Base's destructor is not virtual and b is a Base* pointing to a Derived object, delete b has undefined behaviour. The destructor in the base class must always be virtual to avoid this. 

### Shadowing (name hiding) in C++
Each block in C++ defines its own scope region. So what happens when we have a variable inside a nested block that has the same name as a variable in an outer block? When this happens, the nested variable hides the outer variable in areas where they are both in scope. This is called shadowing or name hiding. Generally this should be avoided, and we can for example use the -Wshadow flag to avoid this.

### Sub-typing polymorphism
Most of the video on this subject is explained under the Virtual section.

### Abstract Classes and Interfaces
```
class ACharacter {
    public:
        virtual void     attack(std::string const & target) = 0;
}
```
In the above code, attack is a "pure" method. This means we cannot IMPLEMENT this function. There is no definition of what this method do. This also means we cannot instantiate this class. In other words, this class is abstract. We generally prefix a capital 'A' to an abstract class.

In the above example, a character itself does not have an attack. The subclasses will have the attack method implemented. If the method is not instantiated in the subclass either, that subclass cannot be instantiated either.

We can also implement a class that has only abstract behaviours. This is what we call an "Interface". We generally prefix this Class with a capital 'I'.

### Shallow vs Deep Copies C++
In general, creating a copy of an object means to create an exact replica, having the same literal values, types and resources.

Depending on the dynamic memory held by an object, we need to perform either a deep or a shallow copy. If an object has data defined in the heap section, a copy can either be a deep or shallow copy.

1. A shallow copy is a copy where the dynamically-allocated data is shared (same memory address) as the object from which it is copied.
2. A deep copy, creates a copy on the heap of the dynamically-allocated data. Therefore, changes to the original object after copying are not reflected in the copied object.

### Nested Classes
You can nest classes inside of class definitions. If we would instantiate a Leg class inside of a Cat class, we can then instantiate a class of Cat::Leg in the main. 

### Exceptions
Exceptions are runtime anomalies that a program encounters during its execution. There are two types of exceptions:
1. Synchronous
2. Asynchronous (beyond program control such as disk failure, keyboard interrupt)

To handle exceptions, C++ provides us with `try` and `catch` keywords. Within a try block we will put a piece of code that can throw an exception. The catch block is executed only when the try block has thrown an exception. 

The main advantages of using exceptions are:
1. Separation of Error Handling Code from normal code. In traditional error-handling, there are always if-else conditions to handle errors. These conditions and the code to handle errors get mixed up with the normal flow. This makes the code less readable and maintainable. With try/catch blocks, the code for error handling becomes separate from the normal flow.

2. Functions and methods can handle only the exceptions they choose. A function can throw many exceptions, but may choose to handle some of them. The other exceptions, which are thrown but not caught, can be handled by the caller. If the caller chooses not to catch them, then the exceptions are handled by the caller of the caller. In C++, a function can specify the exceptions that it throws using the throw keyword. The caller of this function must handle the exception in some way (either by specifying it again or catching it).

3. Grouping of Error Types: In C++, both basic types and objects can be thrown as exceptions. We can create a hierarchy of exception objects, groupe exceptions in namespaces or classes and categorize them according to their types.

Errors can occur because of:
1. Coding error made by programmer
2. Wrong input error
3. Other unforeseeable things

Normally, execution will stop and an error message is generated. The technical term for this, C++ throws an exception (error).

#### C++ Try and catch
*try* : the try statement allows us to define a block of code to be tested for errors
*throw* : the throw keyword throws an exception when a problem is detected
*catch* : the catch statement allows you to define a block of code to be executed if an error occurs in the try block. 

std::exception::what aka `virtual const char* what() const throw();` is going to return a pointer with a description of the related exception. If we want to give pointer on an excepton subclass that we made, we must overload this function in our child class.

### Casting in C
In C, there is both implicit and explicit casting. Often we have been doing implicit casts but we have not noticed it because they have happened automatically. Both of these casts can have behave differently. 

#### Conversion
```
void    dump_32bits_integer(int const n);
void    dump_64bits_integer(double const z);

int main(void) {
    int     a = 42;

    double  b = a;          // implicit conversion cast
    double  c = (double)a;  // explicit conversion cast

    double  d = a;          // Ok no problem -> converting to a more precise type
    int     e = d;          // Loss of precision happens here. Hazardous!
    int     f = (int)d;     // Instead of the above, we better do this. In this way, we signal to the compiler that we absolutely accept the loss of precision.

    dump_32bits_integer(a);

    dump_64bits_integer(b);
    dump_64bits_integer(c);

    dump_64bits_integer(d);
    dump_32bits_integer(e);
    dump_32bits_integer(f);
}
```

In the above example, we see a conversion between integers and doubles. A double has a very different internal representation. Both b and c have the same underlying bit values.

Additionally, there is a hierarchy in types of numbers. When we convert into a more precise type, generally there is no problem, but what happens when we convert to a less precise type? We can have precision loss in this case. When cascading calculations in this way, margins of errors can increase exponentially when having many numbers with precision loss. 

If we want to avoid precision loss, we can use the flag -Wnoconversion which will prohibit implicit casts when precision is lost. 

#### C type reinterpretation
Above conversions change the bit layouts of the underlying number, but keep the number the same. There is also a way to keep the bit layout when converting a number. We call this reinterpreting a number. In the below example, we are making use of void pointers because they are type-agnostic. They can point to an address of any type.

```
int main(void){
    float a =       420.042f;

    void* b =       &a;         // Implicit reinterpretation cast
    void* c =       (void*)&a;  // Explicit reinterpretation cast

    void* d =       &a;
    int*  e =       d;
    int*  f =       (int *)d;

    printf("%p, %f\n", &a, a);

    printf("%p\n", b);
    printf("%p\n", c);

    printf("%p\n", d);
    printf("%p, %d\n", e, *e);
    printf("%p, %d\n", f, *f);
}
```

#### Type qualifier reinterpretation
Here we will cast ints into const ints. The two type qualifiers this applies to is const and volatile. 

```
int main(void){
    int         a =       420.042f;

    int const * b =       &a;         // Implicit reinterpretation cast
    int const * c =       (void*)&a;  // Explicit reinterpretation cast

    int const * d =       &a;
    int*        e =       d;
    int*        f =       (int *)d;

    printf("%p, %f\n", &a, a);

    printf("%p\n", b);
    printf("%p\n", c);

    printf("%p\n", d);
    printf("%p, %d\n", e, *e);
    printf("%p, %d\n", f, *f);
}
```

### Casting in C++
#### Upcasting and downcasting
We can reinterpret casts as well with classes in C++. For example, we can cast the address of a child into an address of the parent type. A parent is a less specialized type of a child and a child is a more specialized type of a parent class. 

Similarly to the above explanations in C, we can downcast a parent into a type of child, but we have to do it explicitly!

A problem can arise when we upcast a Child1 to a Parent, then downcast the parent back to a subclass which is not Child1 but for example Child2. This will compile but will cause problems upon executing.

#### Static Casts

There are 5 types of casts:
1. Conversion
2. Reinterpretation
3. Change of type qualifier
4. Downcasts
5. Upcasts

C-style casts cannot do safe downcasting. The new casting in C++ is introduced to make it very clear to the compiler what the programmer wants to do.

Static cast is the simplest type of cast that can be used. It is a compile time cast. It does things like implicit conversions between types and it can also can explicit conversion functions.

```
int     a = 42;
double  b = a;                      // OK
int     c = b;                      // No, loss of precision
int     d = static_cast<int>(b);    // Ok, compiler obeys
```

The above can also be done with classes:
```
int main(void)
{
    Child1      a;

    Parent*     b = &a;                         // OK
    Child1*     c = b;                          // not allowed
    Child2*     d = static_cast<Child2 *>(b);   // explicitly, ok compiler obeys
}
```

In the above code, if we replace Child2 on the 4th statement with an unrelated class (no inherited child/parent class), the compiler will complain. 

#### Dynamic casts
A dynamic cast in C++ is mainly used for safe downcasting at run time. To work on dynamic_cast there must be one virtual function in the base class. A dynamic_cast works only on polymorphic base classes because it uses this information to decide safe downcasting.

Dynamic casting will take place at execution instead of at compilation! A program can compile but the dynamic cast can fail during execution. This means when working with dynamic casts, we need to make sure in our code the failsafes are in place. 

```
int main(void)
{
    Child1      a;
    Parent*     b = &a;

    // Explicit downcast
    Child1* c = dynamic_cast<Child1 *>(b);
    if (c == NULL) {
        std::cout << "Conversion is NOT Ok" << std::endl;
    } else {
        std::cout << "Conversion is OK" << std::endl; 
    }

    // ALTERNATIVE
    try {
        Child2&     d = dynamic_cast<Child2 &>(*b); // Child2 here, this will fail!
        std::cout << "Conversion is Ok" << std::endl;
    } catc (std::bad_cast &bc) {
        std::cout << "Conversion is not OK" << bc.what() << std::endl;
        return (0);
    }

}
```