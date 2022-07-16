# LIBFT: Your very own first library

## Project Goal
The goal of the first 42 project is to gain a deeper understanding in the functions we take for granted every day and are quick to use in other higher level languages. We'll write a bunch of string and memory manipulation functions for the mandatory part as well as linked-list manipulation functions for the bonus part.

## Install & Run
Create the library (.a format) by running the make command after cloning the repository. Functions within the library can be used with other programs by compiling together with gcc.

## Project Approach
This project consists of multiple exercises and is quite self-explanatory.

## Key Learnings
1. C libraries:
	* The functions in our libft are an odd match of functions from stdio.h, string.h, stdlib.h and others.
2. Library compilation and reusability:
	* We can compile libraries using Makefiles, in which we define how a program must be defined. Makefiles have very specific formatting rules
	* There are 4 steps in compilation in c: preprocessing, compiling, assembling and linking.
	* In our makefile, we describe how the compiler should turn our code into object code during the assembly phase. At the last phase, linking, we can link in additional libraries which were already pre-compiled.
3. Linked Lists
	* Benefits:
		1. Insertion and deletion is easier for memory than working with arrays, because no continuous space must be reserved in memory for the linked list.
		2. With large records, moving pointers is faster than moving the data itself.
		3. Overflow of memory can not occur unless the memory is actually full.
		4. Can grow and shrink at runtime without the need to define list length upfront.
	* Drawbacks:
		1. Memory usage is higher than arrays, because a pointer (of 8 bytes) is also required.
		2. Traversal is more time consuming
		3. Reverse traversal of a singly-linked list is not possible.
		4. Random access of the list is not possible due to its dynamic memory allocation. To find an item, we must start from the start of the list.
4. Stack and Heap:
	* The Stack: When writing C programs, we generally start at the main. This function is allocated some memory on the stack portion of memory and every function call thereafter within this main is allocated some memory on the top of the stack of memory. When a function completes its task, memory that was allocated on the stack is deallocated. If too many functions are called (such as in a recursive function), the stack can overflow.
	* The Heap: The stack does have some limitations. Let's say we want to define an array in a function which is not the main and return a pointer to that array. If defined in a function on the stack and then returned, the memory is deallocated. For this problem, we can make use of the heap, which is a part of memory that is available for the programmer to store data, at the risk of it being the programmer's own responsibility to free this memory after usage. We can use the functions malloc and free for this.
