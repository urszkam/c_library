# C library - in progress
This project focuses on creating a custom C library, providing essential functions for C assignments at 42 Warsaw. The library includes libc function replicas and additional utilities.

# Table of Contents
- [Functions](#functions)
    - [Libc Functions](#libc-functions)
    - [Additional Functions](#additional-functions)
    - [Linked List Functions](#linked-list-functions)
- [Getting Started](#getting-started)
    - [Prerequiitions](#libc-functions)
    - [Build The Library](#build-the-library)
    - [Usage](#usage)
    - [Cleanup](#cleanup)

# Functions
## Libc Functions
Replics of functions from the libc with names prefixed by 'ft_'
1. **ft_isalpha:** Checks if a character is alphabetic.
2. **ft_isdigit:** Checks if a character is a digit.
3. **ft_isalnum:** Checks if a character is alphanumeric.
4. **ft_isascii:** Checks if a character is ASCII.
5. **ft_isprint:** Checks if a character is printable.
6. **ft_strlen:** Calculates string length.
7. **ft_memset:** Fills memory with a constant byte.
8. **ft_bzero:** Sets the first n bytes of memory to zero.
9. **ft_memcpy:** Copies memory area.
10. **ft_memmove:** Copies memory area with overlapping.
11. **ft_strlcpy:** Copies string up to size characters.
12. **ft_strlcat:** Concatenates strings with size control.
13. **ft_toupper:** Converts character to uppercase.
14. **ft_tolower:** Converts character to lowercase.
15. **ft_strchr:** Locates character in string.
16. **ft_strrchr:** Locates character in string (reverse).
17. **ft_strncmp:** Compares the first n characters of two strings.
18. **ft_memchr:** Locates byte in byte string.
19. **ft_memcmp:** Compares memory areas.
20. **ft_strnstr:** Locates substring in a string with size control.
21. **ft_atoi:** Converts a string to an integer.

## Additional functions
Extra utilities like substring creation, string concatenation, and integer-to-string conversion.
1. **ft_substr:** Extracts a substring from a string. Returns substring.
2. **ft_strjoin:** Concatenates two strings into a new one. Returns result.
3. **ft_strtrim:** Trims specified characters from the string. Returns trimmed string.
4. **ft_split:** Splits a string into an array of substrings. Returns array.
5. **ft_itoa:** Converts an integer to a string. Returns string.
6. **ft_strmapi:** Applies a function to each character in a string. Returns result.
7. **ft_striteri:** Applies a function to each character in a string.
8. **ft_putchar_fd:** Outputs a character to a file descriptor.
9. **ft_putstr_fd:** Outputs a string to a file descriptor.
10. **ft_putendl_fd:** Outputs a string followed by a newline to a file descriptor.
11. **ft_putnbr_fd:** Outputs an integer to a file descriptor.

## Linked List Functions
Linked list manipulation functions
1. **ft_lstnew:** Creates a new list node.
2. **ft_lstadd_front:** Adds a node to the front of the list.
3. **ft_lstsize:** Gets the number of nodes in a list.
4. **ft_lstlast:** Gets the last node of a list.
5. **ft_lstadd_back:** Adds a node to the end of the list.
6. **ft_lstdelone:** Deletes a single node, and frees content using the provided function.
7. **ft_lstclear:** Deletes the entire list, and frees content using the provided function.
8. **ft_lstiter:** Iterates through the list and applies a function to each node's content.
9. **ft_lstmap:** Creates a new list resulting from applying a function to each node's content.

# Getting started

To run and use the libft library, follow these steps:

## Prerequisites
Ensure you have the following installed on your system:

- C Compiler (e.g., GCC)
- Make

## Clone the Repository
Clone the libft repository to your local machine:

```bash
git clone https://github.com/urszkam/c_library.git libft
```

## Build the Library
Navigate to the libft directory and use the provided Makefile to build the library:

```bash
cd libft
make
```

This command will compile the source files and create the libft.a library.

## Usage
In your C source code file, include the libft.h header file at the beginning to have access to the function prototypes.

```c
#include "libft.h"
```
Then compile your main program using the command:

```bash
cc -o my_program main.c -L. -lft -I./
```

## Cleanup
If needed, you can clean the generated files using:

```bash
make clean
```
This removes the object files but keeps the compiled library (libft.a). 
To remove both object files and the library, use:

```bash
make fclean
```
Now you're ready to integrate and use the libft library in your C projects. Explore the provided functions and adapt them to your specific needs.
