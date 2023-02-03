# GET_NEXT_LINE: An exploration of static variables

![Score](extras/score.png)

![Example GIF](extras/gnl.gif)

## Project Goal
In this project the goal is to write a function that takes a file descriptor (int) and returns the first string before the first newline character or EOF. An example of this, let's say an open file descriptor points to a file with contents: "hello\nthere\ndude". Calling the get_next_line function the first time yields "hello", while consequent runs yield "there" and "dude". Finally, if there is no content remaining in the file, (null) will be returned.

## Install & Run
The project is in the required format for 42-school bot "Moulinette". To use the get_next_line function in your own program, add these files to the LIBFT Makefile to include them in the LIBFT library or add a main.c file and run directly.

## Project Approach
It is key to understand file descriptors and the **open(2)** as well as **read(2)** function well for this assignment. Additionally, because the read(2) function reads using a set BUFFER_SIZE (we define this with flags "-D") and the assignment does not allow lseek(2) we must use a static variable to keep information after reading between function calls. For example, let's say we call `read(fd, *buff, BUFFER_SIZE)`, then we have read BUFFER_SIZE bytes from the file descriptor. This changes the underlying offset and the next time read(2) is called, it reads as of the byte BUFFER_SIZE + 1. This offset can be reset by calling lseek(2) but because this is not allowed in this project, the need for a static variable is clear. If our BUFFER_SIZE is greater than the amount of characters before the first '\n', there can be more '\n' in the buffer, which need to be checked for before the next read call. Therefore, before reading, we must always first check if there is something in the buffer from a previous read call. If there is, return the string until the first '\n'. If there is no '\n', we put it in the output and add accordingly from the next read call.

## Key Learnings
1. **Static Variables**: Static variables' allocated memory lives in a dedicated area reserved for static and global variables. Therefore, it is not deallocated after a function's memory is deallocated. Because the BUFFER_SIZE is a constant, it makes sense to use static memory allocation here instead of dynamic memory allocation. Static allocation runs faster but the size of allocated memory needs to be predefined.
2. **File Descriptors**: When files are opened, C creates an addition to a table with integer file descriptors. 0, 1 and 2 are reserved for stdin, stdout and stderr respectively. If we open a new file, the file descriptor allocated would be 3. This integer reference is then used throughout the program. At the end of its use, it is best to close this file descriptor and avoid leaks.
3. **Read(2)** : the read(2) function can fail and it is imperative to check for returns of (-1). If you don't do this and the read call fails (eg because of a buffer issue, or attempting to read from a corrupted file), then your program undefined behaviour can happen or your program can crash. It's also important to keep the return of the read(2) call to know the current value of the offset (bytes read).
