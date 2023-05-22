# [LEARN C++](https://www.learncpp.com/)

## 11.1 — Arrays (Part I)
    
```cpp
// allocate 30 integer variables (each with a different name)
int testScoreStudent1{};
int testScoreStudent2{};
int testScoreStudent3{};
// ...
int testScoreStudent30{};

// allocate 30 integer variables (each with the same name)
int testScore[30]{};
```

Because fixed arrays have memory allocated at compile time, that introduces two limitations:

Fixed arrays cannot have a length based on either user input or some other value calculated at runtime.

Fixed arrays have a fixed length that can not be changed.

In many cases, these limitations are problematic. Fortunately, C++ supports a second kind of array known as a dynamic array. The length of a dynamic array can be set at runtime, and their length can be changed. However, dynamic arrays are a little more complicated to instantiate, so we’ll cover them later in the chapter.

## 11.2 — Arrays (Part II)

```cpp
int prime[5]{ 2, 3, 5, 7, 11 }; // use initializer list to initialize the fixed array
// If there are more initializers in the list than the array can hold, the compiler will generate an error.

// However, if there are less initializers in the list than the array can hold, the remaining elements are initialized to 0 (or whatever value 0 converts to for a non-integral fundamental type -- e.g. 0.0 for double). This is called zero initialization.

int array[5]{};          // Initialize all elements to 0
double array[5] {};      // Initialize all elements to 0.0
std::string array[5] {}; // Initialize all elements to an empty string
```

Determining the length of an array
```cpp
#include <iostream>
#include <iterator> // for std::size

int main()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "The array has: " << std::size(array) << " elements\n";

    return 0;
}
```
std::size() was added in C++17. If you’re still using an old compiler, you have to use the sizeof operator instead. sizeof isn’t as easy to use as std::size() and there are a few things you have to watch out for. If you’re using a C++17-capable compiler, you can skip to section “Indexing an array out of range”.

The sizeof operator can be used on arrays, and it will return the total size of the array (array length multiplied by element size).


```cpp
#include <iostream>

int main()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) << '\n'; // will print the size of the array multiplied by the size of an int, 32
    std::cout << sizeof(int) << '\n'; // will print the size of an int, 4

    return 0;
}
```
```cpp
#include <iostream>

int main()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "The array has: " << sizeof(array) / sizeof(array[0]) << " elements\n";

    return 0;
}
```














































































