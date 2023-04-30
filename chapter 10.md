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

Unscoped enumerations are defined via the enum keyword.

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
















































































































































































