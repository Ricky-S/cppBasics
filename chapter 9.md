# [LEARN C++](https://www.learncpp.com/)


## 9.1 — Introduction to compound data types
C++ supports the following compound types:

+ Functions
+ Arrays
+ Pointer types:
+ + Pointer to object
+ + Pointer to function
+ Pointer to member types:
+ + Pointer to data member
+ + Pointer to member function
+ Reference types:
+ + L-value references
+ + R-value references
+ Enumerated types:
+ + Unscoped enumerations
+ + Scoped enumerations
+ Class types:
+ + Structs
+ + Classes
+ + Unions

## 9.3 — Lvalue references

```cpp
int      // a normal int type
int&     // an lvalue reference to an int object
double&  // an lvalue reference to a double object

int& invalidRef;   // error: references must be initialized

int x { 5 };    // x is a normal integer variable
int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x
// okay: reference to int is bound to int variable

    int x { 5 };
    int& ref { x }; // valid: lvalue reference bound to a modifiable lvalue

    const int y { 5 };
    int& invalidRef { y };  // invalid: can't bind to a non-modifiable lvalue
    int& invalidRef2 { 0 }; // invalid: can't bind to an r-value


```

**For those of you already familiar with pointers, the ampersand in this context does not mean “address of”, it means “lvalue reference to”.**

## 9.4 — Lvalue references to const
```cpp
int main()
{
    // This is disallowed because it would allow us to modify a const variable (x) through the non-const reference (ref).
    const int x { 5 }; // x is a non-modifiable (const) lvalue
    int& ref { x }; // error: ref can not bind to non-modifiable lvalue

    return 0;
}

int main()
{
    const int x { 5 };    // x is a non-modifiable lvalue
    const int& ref { x }; // okay: ref is a an lvalue reference to a const value

    return 0;
}
```

Lvalue references can only bind to modifiable lvalues.

Lvalue references to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues. This makes them a much more flexible type of reference.


## 9.5 — Pass by lvalue reference

```cpp
#include <iostream>
#include <string>

void printValue(std::string y)
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" }; // x is a std::string

    printValue(x); // x is passed by value (copied) into parameter y (expensive)

    return 0;
}
```
Pass by reference

One way to avoid making an expensive copy of an argument when calling a function is to use pass by reference instead of pass by value. When using pass by reference, we declare a function parameter as a reference type (or const reference type) rather than as a normal type. When the function is called, each reference parameter is bound to the appropriate argument. Because the reference acts as an alias for the argument, no copy of the argument is made.

Here’s the same example as above, using pass by reference instead of pass by value:

```cpp
#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}
```
This program is identical to the prior one, except the type of parameter y has been changed from std::string to std::string& (an lvalue reference). Now, when printValue(x) is called, lvalue reference parameter y is bound to argument x. Binding a reference is always inexpensive, and no copy of x needs to be made. Because a reference acts as an alias for the object being referenced, when printValue() uses reference y, it’s accessing the actual argument x (rather than a copy of x).

```cpp
#include "dbg.h"
#include <iostream>
// uses reference y, it’s accessing the actual argument x (rather than a copy of x).
void addOne(int& y)
{
    std::cout << "y = " << y << std::endl; // x = 1
    y++;
    std::cout << "y = " << y << std::endl; // x = 2
}

int main()
{

    int x = 1;
    std::cout << "x = " << x << std::endl; // x = 1
    addOne(x);

    std::cout << "x = " << x << std::endl; // x = 2

	return 0;
}
```
Pass by reference to non-const can only accept modifiable lvalue arguments
```cpp
#include <iostream>
#include <string>

void printValue(int& y) // y only accepts modifiable lvalues
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // error: z is a non-modifiable lvalue

    printValue(5); // error: 5 is an rvalue

    return 0;
}
```
Pass by const reference
```cpp
#include <iostream>
#include <string>

void printValue(const int& y) // y is now a const reference
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // ok: z is a non-modifiable lvalue

    printValue(5); // ok: 5 is a literal rvalue

    return 0;
}
```
Because class types can be expensive to copy (sometimes significantly so), class types are usually passed by const reference instead of by value to avoid making an expensive copy of the argument. Fundamental types are cheap to copy, so they are typically passed by value.

**Pass fundamental types by value, and class (or struct) types by const reference.**

For objects that are cheap to copy, the cost of copying is similar to the cost of binding, so we favor pass by value so the code generated will be faster.

For objects that are expensive to copy, the cost of the copy dominates, so we favor pass by (const) reference to avoid making a copy.

Prefer pass by value for objects that are cheap to copy, and pass by const reference for objects that are expensive to copy. If you’re not sure whether an object is cheap or expensive to copy, favor pass by const reference.

Common types that are cheap to copy include all of the fundamental types, enumerated types, and std::string_view.\
Common types that are expensive to copy include std::array, std::string, std::vector, and std::ostream.

## 9.6 — Introduction to pointers

**The address-of operator (&)**
```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x 0x6dde3ffaec
    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)
    return 0;
}

```
it has different meanings depending on context:

When following a type name, & denotes an lvalue reference: int& ref.

When used in a unary context in an expression, & is the address-of operator: std::cout << &x.

When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.


**The dereference operator (*)**

The most useful thing we can do with an address is access the value stored at that address. The dereference operator (*) (also occasionally called the indirection operator) returns the value at a given memory address as an lvalue.


**Given a memory address, we can use the dereference operator (*) to get the value at that address (as an lvalue).**

A **pointer** is an object that holds a memory address (typically of another variable) as its value. This allows us to store the address of some other object to use later.

```cpp
int;  // a normal int
int&; // an lvalue reference to an int value

int*; // a pointer to an int value (holds the address of an integer value)
```

**Always initialize your pointers.**

```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n'; //5,  print the value of variable x

    int* ptr{ &x }; // ptr holds the address of x. ptr: pointer.
    std::cout << *ptr << '\n'; // 5, use dereference operator to print the value at the address that ptr is holding (which is x's address)

    return 0;
}
```
This is where pointers get their name from -- ptr is holding the address of x, so we say that ptr is “pointing to” x.

```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // initialize ptr with address of variable x

    std::cout << x << '\n';    // print x's value 5
    std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address) 5

    *ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)

    std::cout << x << '\n';// 6
    std::cout << *ptr << '\n'; //6, print the value at the address that ptr is holding (x's address)

    return 0;
}
```

```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x, ptr is the address.

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

    return 0;
}
```

## 9.7 — Null pointers
```cpp
int main()
{
    int* ptr {}; // ptr is now a null pointer, and is not holding an address

    return 0;
}
```














































