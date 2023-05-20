# [LEARN C++](https://www.learncpp.com/)


## 10.1 — Introduction to program-defined (user-defined) types

```cpp
// Define a program-defined type named Fraction so the compiler understands what a Fraction is
// (we'll explain what a struct is and how to use them later in this chapter)
// This only defines what a Fraction type looks like, it doesn't create one
// Name your program-defined types starting with a capital letter and do not use a suffix.
struct Fraction
{
	int numerator {};
	int denominator {};
};
// Don’t forget to end your type definitions with a semicolon, otherwise the compiler will typically error on the next line of code.

// Now we can make use of our Fraction type
int main()
{
	Fraction f{ 3, 4 }; // this actually instantiates a Fraction object named f

	return 0;
}
```

## 10.2 — Unscoped enumerations

An enumeration (also called an enumerated type or an enum) is a compound data type where every possible value is defined as a symbolic constant (called an enumerator).

```cpp
using Color = int; // define a type alias named Color

// The following color values should be used for a Color
constexpr Color red{ 0 };
constexpr Color green{ 1 };
constexpr Color blue{ 2 };

int main()
{
    Color appleColor{ red };
    Color shirtColor{ green };

    return 0;
}
```

Unscoped enumerations are defined via the **enum** keyword.

```cpp
// Define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

int main()
{
    // Define a few variables of enumerated type Color
    Color apple { red };   // my apple is red
    Color shirt { green }; // my shirt is green
    Color cup { blue };    // my cup is blue

    Color socks { white }; // error: white is not an enumerator of Color
    Color hat { 2 };       // error: 2 is not an enumerator of Color

    return 0;
}
```

**Name your enumerated types starting with a capital letter. Name your enumerators starting with a lower case letter.**

Because enumerators are descriptive, they are useful for enhancing code documentation and readability. Enumerated types are best used when you have a **smallish set of related constants**, and objects only need to **hold one of those values at a time**.

A better option is to put the enumerated type inside something that provides a separate scope region, such as a namespace:
```cpp
// Prefer putting your enumerations inside a named scope region (such as a namespace or class) so the enumerators don’t pollute the global namespace.
namespace color
{
    // The names Color, red, blue, and green are defined inside namespace color
    enum Color
    {
        red,
        green,
        blue,
    };
}

namespace feeling
{
    enum Feeling
    {
        happy,
        tired,
        blue, // feeling::blue doesn't collide with color::blue
    };
}

int main()
{
    color::Color paint { color::blue };
    feeling::Feeling me { feeling::blue };

    return 0;
}
```

## 10.5 — Introduction to **structs**, members, and member selection

A struct (short for structure) is a program-defined data type that allows us to bundle multiple variables together into a single type. As you’ll see shortly, this makes management of related sets of variables much simpler!

```cpp
// The struct keyword is used to tell the compiler that we’re defining a struct, which we’ve named Employee (since program-defined types are typically given names starting with a capital letter).
struct Employee
{
    int id {};// called data members (or member variables).
    int age {};
    double wage {};
};
// In C++, a member is a variable, function, or type that belongs to a struct (or class). All members must be declared within the struct (or class) definition.
```

```cpp
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe;
// To access a specific member variable, we use the member selection operator (operator.) in between the struct variable name and the member name. For example, to access Joe’s age member, we’d use joe.age.
    joe.age = 32;  // use member selection operator (.) to select the age member of variable joe

    std::cout << joe.age << '\n'; // print joe's age

    return 0;
}
```

## 10.6 — Struct aggregate initialization

```cpp
struct Employee
{
    int id {};
    int age {};
    double wage {};
};
// Aggregates use a form of initialization called aggregate initialization, which allows us to directly initialize the members of aggregates. To do this, we provide an initializer list as an initializer, which is just a list of comma-separated initialization values.
int main()
{
    Employee frank = { 1, 32, 60000.0 }; // copy-list initialization using braced list
    Employee robert ( 3, 45, 62500.0 );  // direct initialization using parenthesized list (C++20)
    Employee joe { 2, 28, 45000.0 };     // list initialization using braced list (preferred)

    return 0;
}
```

```cpp
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe { 2, 28 }; // joe.wage will be value-initialized to 0.0

    Employee joe1 {}; // value-initialize all members. means 0.

    return 0;
}
```

## 10.7 — Default member initialization

```cpp
struct Something
{
    int x;       // no initialization value (bad)
    int y {};    // value-initialized by default
    int z { 2 }; // explicit default value
};

int main()
{
    Something s1; // s1.x is uninitialized, s1.y is 0, and s1.z is 2

    return 0;
}
```

## 10.8 Struct passing and miscellany
```cpp
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Company
{
    int numberOfEmployees {};
    Employee CEO {}; // Employee is a struct within the Company struct
};

int main()
{
    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
    std::cout << myCompany.CEO.wage; // print the CEO's wage
}
```


## 10.9 — Member selection with pointers and references

When using a pointer to access the value of a member, use the member selection from pointer operator (->) instead of the member selection operator (.).


```cpp
#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    Employee* ptr{ &joe };
    std::cout << ptr.id << '\n'; // Compile error: can't use operator. with pointers
    std::cout << (*ptr).id << '\n'; // Not great but works: First dereference ptr, then use member selection
    std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object
    //This member selection from pointer operator (->) works identically to the member selection operator (.) but does an implicit dereference of the pointer object before selecting the member. Thus ptr->id is equivalent to (*ptr).id.
    return 0;
}
```

## 10.10 — Class templates
```cpp
#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

int main()
{
    Pair<int> p1{ 5, 6 };        // instantiates Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double> p2{ 1.2, 3.4 }; // instantiates Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double> p3{ 7.8, 9.0 }; // creates object p3 using prior definition for Pair<double>
    std::cout << p3.first << ' ' << p3.second << '\n';

    return 0;
}
```

```cpp
template <typename T>
struct Pair
{
    T first{};
    T second{};
};
// what if we want to have a Pair where the first member is an int and the second member is a double? We can do this by providing multiple template parameters:
template <typename T1, typename T2>
struct Pair
{
    T1 first{};
    T2 second{};
};
```
```
















































































































































