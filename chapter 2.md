# [LEARN C++](https://www.learncpp.com/)


## 2.1 — Introduction to functions
```cpp
returnType functionName() 
// This is the function header (tells the compiler about the existence of the function)
{
    // This is the function body (tells the compiler what the function does)
}

// OR
return-type identifier() // identifier replaced with the name of your function
{
// Your code here
}
```
## 2.2 — Function return values (value-returning functions)

modular programming: the ability to write a function, test it, ensure that it works, and then know that we can reuse it as many times as we want and it will continue to work (so long as we don’t modify the function -- at which point we’ll have to retest it).


## 2.5 — Introduction to local scope

**Define your local variables as close to their first use as reasonable.**

## 2.6 — Why functions are useful, and how to use them effectively

**Effectively using functions**

One of the biggest challenges new programmers encounter (besides learning the language) is understanding when and how to use functions effectively. Here are a few basic guidelines for writing functions:

+ Groups of statements that appear **more than once in a program** should generally be made into a function. For example, if we’re reading input from the user multiple times in the same way, that’s a great candidate for a function. If we output something in the same way in multiple places, that’s also a great candidate for a function.\
+ Code that has a **well-defined set of inputs and outputs** is a good candidate for a function, (particularly if it is complicated). For example, if we have a list of items that we want to sort, the code to do the sorting would make a great function, even if it’s only done once. The input is the unsorted list, and the output is the sorted list. Another good prospective function would be code that simulates the roll of a 6-sided dice. Your current program might only use that in one place, but if you turn it into a function, it’s ready to be reused if you later extend your program or in a future program.\
+ A function should generally perform **one (and only one) task**.\
+ When a function becomes too long, too complicated, or hard to understand, it can be split into multiple sub-functions. This is called refactoring. 

## 2.7 — Forward declarations and definitions

```cpp
#include <iostream>
// easily create function declarations by copy/pasting your function’s header and adding a semicolon.
int add(int x, int y); // forward declaration of add() (using a function declaration)
// OR
int add(int, int); // not preferred.

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}
```

Definition\
 Implements a function or instantiates a variable.
Definitions are also declarations.\
Declaration\
Tells compiler about an identifier.
Does not create the object or function.\


## 2.10 — Introduction to the preprocessor


When the preprocessor encounters this directive, any further occurrence of the identifier is replaced by substitution_text. The identifier is traditionally typed in all capital letters, using underscores to represent spaces.

```cpp
#define MY_NAME "Alex"
```

**Conditional compilation**

**#ifdef, #ifndef, and #endif.**

The #ifdef preprocessor directive allows the preprocessor to check whether an identifier has been previously #defined. If so, the code between the #ifdef and matching #endif is compiled. If not, the code is ignored.

```cpp
#include <iostream>

#define PRINT_JOE

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

    return 0;
}

# if 0
# endif

# if 1
# endif
```

+ **If a header file is paired with a code file (e.g. add.h with add.cpp), they should both have the same base name (add).**

+ **Source files should #include their paired header file (if one exists).**

+ **Use double quotes to include header files that you’ve written or are expected to be found in the current directory. Use angled brackets to include headers that come with your compiler, OS, or third-party libraries you’ve installed elsewhere on your system.**

### Including header files from other directories

```sh
# A better method is to tell your compiler or IDE that you have a bunch of header files in some other location, so that it will look there when it can’t find them in the current directory. This can generally be done by setting an include path or search directory in your IDE project settings.

# Using g++, you can use the -I option to specify an alternate include directory:
g++ -o main -I/source/includes main.cpp
```

order your #includes as follows:

+ The paired header file
+ Other headers from your project
+ 3rd party library headers
+ Standard library headers
+ The headers for each grouping should be sorted alphabetically.


## 2.12 — Header guards

```cpp
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif

// Modern compilers support a simpler, alternate form of header guards using the #pragma directive:
#pragma once
// your code here
```














