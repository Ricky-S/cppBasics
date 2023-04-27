# [LEARN C++](https://www.learncpp.com/)


## 8.1 — Implicit type conversion (coercion)
```cpp
double d{ 3 }; // int value 3 implicitly converted to type double
d = 6; // int value 6 implicitly converted to type double

float doSomething()
{
    return 3.0; // double value 3.0 implicitly converted to type float
}

double division{ 4.0 / 3 }; // int value 3 implicitly converted to type double

if (5) // int value 5 implicitly converted to type bool

int x { 3.5 }; // brace-initialization disallows conversions that result in data loss
int x = 3.5; //works.
```

## 8.2 — Floating-point and integral promotion

A **numeric promotion** is the type conversion of a narrower numeric type (such as a **char**) to a wider numeric type (typically **int** or **double**) that can be processed efficiently and is less likely to have a result that overflows.

All numeric promotions are **value-preserving**.

```cpp
double d{ 5.0 };

    someFcn(d); // bad: will generate compiler warning about narrowing conversion
    someFcn(static_cast<int>(d)); // good: we're explicitly telling the compiler this narrowing conversion is expected, no warning generated
```

Avoid narrowing conversions whenever possible. \
**If you do need to perform one, use static_cast to make it an explicit conversion.**


## 8.7 — Type deduction for objects using the auto keyword

**Type deduction for initialized variables**

Type deduction (also sometimes called type inference) is a feature that allows the compiler to deduce the type of an object from the object’s initializer. To use type deduction, the **auto** keyword is used in place of the variable’s type:

```cpp
int main()
{
    auto d{ 5.0 }; // 5.0 is a double literal, so d will be type double
    auto i{ 1 + 2 }; // 1 + 2 evaluates to an int, so i will be type int
    auto x { i }; // i is an int, so x will be type int too

    return 0;
}
```
```cpp
int main()
{
    const int x { 5 };  // x has type const int
    auto y { x };       // y will be type int (const is dropped)

// If you want a deduced type to be const, you must supply the const yourself. To do so, simply use the const keyword in conjunction with the auto keyword:
    const auto z { x }; // z will be type const int (const is reapplied)
}
```

```cpp
auto s { "Hello, world" }; // s will be type const char*, not std::string

    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view
```

Use type deduction for your variables, unless you need to commit to a specific type.


## 8.8 — Type deduction for functions
```cpp
auto add(int x, int y)
{
    return x + y;
}
```
## 8.9 — Introduction to function overloading

```cpp
// Functions can be overloaded so long as each overloaded function can be differentiated by the compiler. If an overloaded function can not be differentiated, a compile error will result.
int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int main()
{
    return 0;
}

```

## 8.12 — Default arguments
```cpp
#include <iostream>

void print(int x, int y=4); // forward declaration

void print(int x, int y=4) // error: redefinition of default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
```
```cpp
//  foo.h
#ifndef FOO_H
#define FOO_H
void print(int x, int y=4);
#endif

// main.cpp
#include "foo.h"
#include <iostream>

void print(int x, int y)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    print(5);

    return 0;
}
```

## 8.13 — Function templates

```cpp
// 3 int here, x, y, return
int max(int x, int y)
{
    return (x < y) ? y : x;
}

template <typename T> // this is the template parameter declaration
// Use a single capital letter (starting with T) to name your type template parameters (e.g. T, U, V, etc…)
T max(T x, T y) // won't compile because we haven't defined T
{
    return (x < y) ? y : x;
}

```

## 8.14 — Function template instantiation
```cpp
max<actual_type>(arg1, arg2); // actual_type is some actual type, like int or double
// 
#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)

    return 0;
}



```

**put all your template code in a header (.h) file instead of a source (.cpp) file.**

**Key insight**

Template definitions are exempt from the part of the one-definition rule that requires only one definition per program, so it is not a problem to have the same template definition #included into multiple source files. And functions instantiated from function templates are implicitly inline, so they can be defined in multiple files, so long as each definition is identical.

**Templates that are needed in multiple files should be defined in a header file, and then #included wherever needed. This allows the compiler to see the full template definition and instantiate the template when needed.**

**Use function templates to write generic code that can work with a wide variety of types whenever you have the need.**


## 8.15 — Function templates with multiple template types
```cpp
#include <iostream>

template <typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem.
    // return is T, which is int.
}

int main()
{
    std::cout << max(2, 3.5) << '\n';

    return 0;
}
```
We can use auto:
```cpp
#include <iostream>

template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n';

    return 0;
}
```

## 8.16 — Non-type template parameters
```cpp
#include <iostream>
// we have our template parameter declaration. Inside the angled brackets, we’re defining a non-type template parameter named N that will be a placeholder for a value of type int. Inside the print() function, we use the value of N.
template <int N> // declare a non-type template parameter of type int named N
void print()
{
    std::cout << N; // use value of N here
}

int main()
{
    print<5>(); // 5 is our non-type template argument

    return 0;
}
```






























































