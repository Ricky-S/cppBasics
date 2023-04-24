# [LEARN C++](https://www.learncpp.com/)


## 6.1 — Compound statements (blocks)

It’s a good idea to **keep your nesting level to 3 or less.** Just as overly-long functions are good candidates for **refactoring** (breaking into smaller functions), overly-nested blocks are hard to read and are good candidates for refactoring (with the most-nested blocks becoming separate functions).

**Keep the nesting level of your functions to 3 or less. If your function has a need for more nested levels, consider refactoring your function into sub-functions.**

## 6.4 — Introduction to global variables
Consider using a “g” or “g_” prefix when naming non-const global variables, to help differentiate them from local variables and function parameters.
```cpp
// Non-constant global variables
int g_x;                 // defines non-initialized global variable (zero initialized by default)
int g_x {};              // defines explicitly zero-initialized global variable
int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global constant

// Constexpr global variables
constexpr int g_y;       // error: constexpr variables must be initialized
constexpr int g_y { 3 }; // defines initialized global const
```

## 6.5 — Variable shadowing (name hiding)
```cpp
#include <iostream>

int main()
{ // outer block
    int apples { 5 }; // here's the outer block apples

    { // nested block
        // apples refers to outer block apples here
        std::cout << apples << '\n'; // print value of outer block apples 5

        int apples{ 0 }; // define apples in the scope of the nested block

        // apples now refers to the nested block apples
        // the outer block apples is temporarily hidden

        apples = 10; // this assigns value 10 to nested block apples, not outer block apples

        std::cout << apples << '\n'; // print value of nested block apples 10
    } // nested block apples destroyed

 
    std::cout << apples << '\n'; // prints value of outer block apples 5

    return 0;
} // outer block apples destroyed
```

## 6.6 — Internal linkage
Global variables with internal linkage are sometimes called internal variables.

To make a non-constant global variable internal, we use the static keyword.

```cpp
#include <iostream>

static int g_x{}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

const int g_y{ 1 }; // const globals have internal linkage by default
constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;
}
```
```cpp
// add.c
// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}
...
```

## 6.7 — External linkage and variable forward declarations

Global variables with external linkage.

Non-const global variables are external by default (if used, the extern keyword will be ignored).


```cpp
int g_x { 2 }; // non-constant globals are external by default

extern const int g_y { 3 }; // const globals can be defined as extern, making them external
extern constexpr int g_z { 3 }; // constexpr globals can be defined as extern, making them external (but this is useless, see the note in the next section)

int main()
{
    return 0;
}
```
Warning

If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think you’re trying to make a forward declaration for the variable.

Warning

Although constexpr variables can be given external linkage via the extern keyword, they can not be forward declared, so there is no value in giving them external linkage.

This is because the compiler needs to know the value of the constexpr variable (at compile time). If that value is defined in some other file, the compiler has no visibility on what value was defined in that other file.

```cpp
// non-constant
int g_x; // variable definition (can have initializer if desired)
extern int g_x; // forward declaration (no initializer)

// constant
extern const int g_y { 1 }; // variable definition (const requires initializers)
extern const int g_y; // forward declaration (no initializer)
```
```cpp
// External global variable definitions:
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_x{ 1 };     // defines initialized const external global variable
extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable

// Forward declarations
extern int g_y;                // forward declaration for non-constant global variable
extern const int g_y;          // forward declaration for const global variable
extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared


```

## 6.10 — Static local variables

**Static local variables**

```cpp
#include <iostream>
// Initialize your static local variables. Static local variables are only initialized the first time the code is executed, not on subsequent calls.
void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}
```
```cpp
// The first time this function is called, it returns 0. The second time, it returns 1. Each time it is called, it returns a number one higher than the previous time it was called. You can assign these numbers as unique IDs for your objects. Because s_itemID is a local variable, it can not be “tampered with” by other functions.
int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}



```

Just like we use “g_” to prefix global variables, it’s common to use “s_” to prefix static (static duration) local variables.

**Initialize your static local variables. Static local variables are only initialized the first time the code is executed, not on subsequent calls.**

**Avoid static local variables unless the variable never needs to be reset.**

Q: What effect does using keyword static have on a global variable? What effect does it have on a local variable?

When applied to a global variable, the static keyword defines the global variable as having internal linkage, meaning the variable cannot be exported to other files.

When applied to a local variable, the static keyword defines the local variable as having static duration, meaning the variable will only be created once, and will not be destroyed until the end of the program.


## 6.13 — Inline functions

**Inline expansion is best suited to simple, short functions (e.g. no more than a few statements), especially cases where a single function call is executed more than once (e.g. function calls inside a loop).**




































































