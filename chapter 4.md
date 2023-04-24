# [LEARN C++](https://www.learncpp.com/)


## 4.1 — Introduction to fundamental data types

**The _t suffix**\
Many of the types defined in newer versions of C++ (e.g. std::nullptr_t) use a _t suffix. This suffix means “type”, and it’s a common nomenclature applied to modern types.

If you see something with a _t suffix, it’s probably a type. But many types don’t have a _t suffix, so this isn’t consistently applied.

## 4.3 — Object sizes and the sizeof operator
```cpp
#include <iostream>

int main()
{
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";

    return 0;
}
// results
bool:           1 bytes
char:           1 bytes
wchar_t:        2 bytes
char16_t:       2 bytes
char32_t:       4 bytes
short:          2 bytes
int:            4 bytes
long:           4 bytes
long long:      8 bytes
float:          4 bytes
double:         8 bytes
long double:    16 bytes
```

## 4.4 — Signed integers

```cpp
short s;      // prefer "short" instead of "short int"
int i;
long l;       // prefer "long" instead of "long int"
long long ll; // prefer "long long" instead of "long long int"

8 bit signed	-128 to 127
16 bit signed	-32,768 to 32,767
32 bit signed	-2,147,483,648 to 2,147,483,647
64 bit signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

// When doing division with two integers (called integer division), C++ always produces an integer result. Since integers can’t hold fractional values, any fractional portion is simply dropped (not rounded!).
std::cout << 8 / 5 << '\n'; // 1, because of 1.6
std::cout << -8 / 5 << '\n'; // -1, because of -1.6

```

## 4.5 — Unsigned integers, and why to avoid them
```cpp
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;

1 byte unsigned	0 to 255
2 byte unsigned	0 to 65,535
4 byte unsigned	0 to 4,294,967,295
8 byte unsigned	0 to 18,446,744,073,709,551,615
```

```cpp
Second, unexpected behavior can result when you mix signed and unsigned integers. In a mathematical operation in C++ (e.g. arithmetic or comparison), if one signed and one unsigned integer are used, the signed integer will be converted to unsigned. And because unsigned integers can not store negative numbers, this can result in loss of data.

#include <iostream>

int main()
{
    signed int s { -1 };
    unsigned int u { 1 };

    if (s < u) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n"; // this statement executes

    return 0;
}
```
## 4.6 — Fixed-width integers and size_t (type)

```cpp
std::int8_t	1 byte signed	    -128 to 127	like a signed char on many systems
std::uint8_t	1 byte unsigned	0 to 255	like an unsigned char
std::int16_t	2 byte signed	-32,768 to 32,767	
std::uint16_t	2 byte unsigned	0 to 65,535	
std::int32_t	4 byte signed	-2,147,483,648 to 2,147,483,647	
std::uint32_t	4 byte unsigned	0 to 4,294,967,295	
std::int64_t	8 byte signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807	
std::uint64_t	8 byte unsigned	0 to 18,446,744,073,709,551,615
```

## 4.8 — Floating point numbers
```cpp
float	4 bytes
double	8 bytes
int x{5}; // 5 means integer
double y{5.0}; // 5.0 is a floating point literal (no suffix means double type by default)
float z{5.0f}; // 5.0 is a floating point literal, f suffix means float type
```
**Favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.**


## 4.9 — Boolean values
```cpp
bool b1 { true };
bool b2 { false };
b1 = false;
bool b3 {}; // default initialize to false

bool b1 { !true }; // b1 will be initialized with the value false
bool b2 { !false }; // b2 will be initialized with the value true
```

## 4.11 — Chars

Char is used to store values that are interpreted as an ASCII character. When using chars, be careful not to mix up ASCII code values and numbers. Printing a char as an integer value requires use of **static_cast**.

**Single chars are always put in single quotes (e.g. 'a', '+', '5'). A char can only represent one symbol (e.g. the letter a, the plus symbol, the number 5).**\
**Text put between double quotes (e.g. “Hello, world!”) is treated as a string.**

## 4.12 — Introduction to type conversion and static_cast

**Whenever you see C++ syntax (excluding the preprocessor) that makes use of angled brackets (<>), the thing between the angled brackets will most likely be a type. This is typically how C++ deals with code that need a parameterized type.**

```cpp
// static_cast takes the value from an expression as input, and returns that value converted into the type specified by new_type (e.g. int, bool, char, double).
static_cast<new_type>(expression)

print( static_cast<int>(5.5) ); // explicitly convert double value 5.5 to an int

    char ch{ 97 }; // 97 is ASCII code for 'a'
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n'; // print value of variable ch as an int
```
**The static_cast operator will produce undefined behavior if the value being converted doesn’t fit in range of the new type.**

## 4.13 — Const variables and symbolic constants

**Constant**\
A variable whose value can not be changed is called a constant variable.

```cpp
const double gravity { 9.8 };  // preferred use of const before type
int const sidesInSquare { 4 }; // "east const" style, okay but not preferred
```

**Prefer constant variables over object-like macros with substitution text.**
```cpp
#include <iostream>
#define MAX_STUDENTS_PER_CLASS 30 // not preferred
int main()
{
    const int maxStudentPerClass { 30 };
}
```

## 4.14 — Compile-time constants, constant expressions, and constexpr

**Compile-time constants**\
A Compile-time constant is a constant whose value is known at compile-time. Literals (e.g. ‘1’, ‘2.3’, and “Hello, world!”) are one type of compile-time constant.

But what about const variables? Const variables may or may not be compile-time constants.

**Runtime const**\
Any const variable that is initialized with a non-constant expression is a runtime constant. Runtime constants are constants whose initialization values aren’t known until runtime.

**The constexpr keyword**\
A constexpr (which is short for “constant expression”) variable can only be a compile-time constant. If the initialization value of a constexpr variable is not a constant expression, the compiler will error.

```cpp
// Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
// Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.
#include <iostream>

// but constexpr int five() works
int five()
{
    return 5;
}

int main()
{
    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    constexpr int myAge { age };      // compile error: age is not a constant expression
    constexpr int f { five() };       // compile error: return value of five() is not a constant expression
    // Although function parameters can be const, they cannot be constexpr.
    // Although 5 is constexpr, the function returns an non-constexpr int, 
    // so it can't be used to init a constexpr variable. 
    // You can return a constexpr int instead to solve this issue.
    return 0;
}
```

## 4.15 — Literals
```cpp
#include <iostream>

int main()
{
    std::cout << 5.0; // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f; // 5.0f is type float

    return 0;
}

// warning
// Because 4.1 has no suffix, the literal has type double, not float.
float f { 4.1 }; // warning: 4.1 is a double literal, not a float literal

// correct:
float f { 4.1f }; // use 'f' suffix so the literal is a float and matches variable type of float
double d { 4.1 }; // change variable to type double so it matches the literal type double
```

## 4.16 — Numeral systems (decimal, binary, hexadecimal, and octal)
```cpp
// c++14 can use '0b'
#include <iostream>

int main()
{
    int bin{};        // assume 16-bit ints
    bin = 0x0001; // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable

// OR
    int bin { 0b1011'0010 };  // assign binary 1011 0010 to the variable
    long value { 2'132'673'462 }; // much easier to read than 2132673462
    // error
    // int bin { 0b'1011'0010 };  // error: ' used before first digit of value
    

    return 0;
}
```



## 4.17 — Introduction to std::string

**Using the extraction operator (>>) with std::cin ignores leading whitespace.\
std::getline() does not ignore leading whitespace unless you use input manipulator std::ws.**


```cpp
#include <string> // allows use of std::string

int main()
{
    std::string name { "Alex" }; // initialize name with string literal "Alex"
    name = "John";              // change name to "John"

    // To read a full line of input into a string, you’re better off using the std::getline() function instead. 
    // If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace.
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    return 0;
}
```
**With normal functions, we call function(object). With member functions, we call object.function().**
```cpp
string name;
// The length() function isn’t a normal standalone function -- it’s a special type of function that is nested within std::string called a member function.
name.length()
```

**Do not pass std::string by value, as making copies of std::string is expensive. Prefer std::string_view parameters.**

## .18 — Introduction to std::string_view C++17

To address the issue with std::string being expensive to initialize (or copy), C++17 introduced std::string_view (which lives in the <string_view> header). \
std::string_view provides read-only access to an existing string (a C-style string literal, a std::string, or a char array) without making a copy.

**Prefer std::string_view over std::string when you need a read-only string, especially for function parameters.**

```cpp
#include <iostream>
#include <string>

void printString(std::string str)
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" };
    printString(s);

    return 0;
}
// SAME AS
#include <iostream>
#include <string_view>

void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);

    return 0;
}
```
Double-quoted string literals are C-style string literals by default. We can create string literals with type std::string_view by using a sv suffix after the double-quoted string literal.
```cpp
#include <iostream>
#include <string>      // for std::string
#include <string_view> // for std::string_view

int main()
{
    using namespace std::literals; // easiest way to access the s and sv suffixes

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    return 0;
};
```

### [summary](https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/)
**Angled brackets are typically used in C++ to represent something that needs a parameterizable type. This is used with static_cast to determine what data type the argument should be converted to (e.g. static_cast<int>(x) will convert x to an int).**



