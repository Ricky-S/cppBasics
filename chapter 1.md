# [LEARN C++](https://www.learncpp.com/)


## 1.2 — Comments
At the library, program, or function level, use comments to describe what.\
Inside the library, program, or function, use comments to describe how.\
At the statement level, use comments to describe why.

## 1.4 — Variable assignment and initialization
**Best practice** 
+ **Favor initialization using braces.**
+ **Initialize your variables upon creation.**





```cpp
// Best practice
// Favor initialization using braces.

int a;         // no initializer (default initialization)
int b = 5;     // initializer after equals sign (copy initialization)

// One of the reasons direct initialization has fallen out of favor is because it makes it hard to differentiate variables from functions.
int c( 6 );    // initializer in parenthesis (direct initialization)

// List initialization methods (C++11) (preferred)
int d { 7 };   // initializer in braces (direct list initialization)
int e = { 8 }; // initializer in braces after equals sign (copy list initialization)

// In most cases, value initialization will initialize the variable to zero (or empty, if that’s more appropriate for a given type). In such cases where zeroing occurs, this is called zero initialization.
int f {};      // initializer is empty braces (value initialization) / zero initialization to value 0
```

## 1.5 — Introduction to iostream: cout, cin, and endl

Best practice

+ Prefer ‘\n’ over std::endl when outputting text to the console.


```cpp
#include <iostream> // for std::cout

int main()
{
    int x{ 5 };
    // the single quotes are needed
    std::cout << "x is equal to: " << x << '\n'; // Using '\n' standalone
    // When embedded into text that is already double-quoted, the single quotes aren’t needed.
    std::cout << "And that's all, folks!\n"; // Using '\n' embedded into a double-quoted piece of text (note: no single quotes when used this way)
    return 0;
}
```

## 1.7 — Keywords and naming identifiers
a list of all the C++ keywords (through C++20)

 the name of a variable (or function, type, or other kind of item) is called an identifier.

+ The identifier can not be a keyword. Keywords are reserved.
+ The identifier can only be composed of letters (lower or upper case), numbers, and the underscore character. That means the name can not contain symbols (except the underscore) nor whitespace (spaces or tabs).
+ The identifier must begin with a letter (lower or upper case) or an underscore. It can not start with a number.
+ C++ is case sensitive, and thus distinguishes between lower and upper case letters. nvalue is different than nValue is different than NVALUE.

```cpp
// it is a convention in C++ that variable names should begin with a lowercase letter.
// If the variable name is one word, the whole thing should be written in lowercase letters.
int value; // correct

int Value; // incorrect (should start with lower case letter)
int VALUE; // incorrect (should start with lower case letter)
int VaLuE; // incorrect (see your psychiatrist) ;)
```

```cpp
// words separated by underscores, called snake_case
int my_variable_name; // correct (separated by underscores/snake_case)
int my_function_name(); // correct (separated by underscores/snake_case)

// intercapped, sometimes called camelCase
int myVariableName; // correct (intercapped/CamelCase)
int myFunctionName(); // correct (intercapped/CamelCase)

int my variable name; // invalid (whitespace not allowed)
int my function name(); // invalid (whitespace not allowed)

int MyVariableName; // valid but incorrect (should start with lower case letter)
int MyFunctionName(); // valid but incorrect (should start with lower case letter)
```
##

```cpp
// For example, x = y = 5 evaluates as x = (y = 5). 
// First y = 5 assigns 5 to y. 
// This operation then returns y, 
// which can then be assigned to x.
// Both operator= and operator<< (when used to output values to the console) return their left operand. 
// Thus, x = 5 returns x, and std::cout << 5 returns std::cout. 
// This is done so that these operators can be chained.
# include<iostream>

int main()
{
    int x, y;
    x = y = 5;
    std::cout << "Hello World!" << std::endl;
    std::cout << "x = " << x << std::endl; // x=5
    std::cout << "y = " << y << std::endl; // y=5
    return 0;
}
```

## 1.11 — Developing your first program
+  Too often new programmers focus on optimizing for performance when they should be optimizing for maintainability.





