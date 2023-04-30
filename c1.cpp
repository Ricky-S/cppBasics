#include "dbg.h"
#include <iostream>
// uses reference y, it’s accessing the actual argument x (rather than a copy of x).
void addOne(int& y)
{
    std::cout << "y = " << y << std::endl; // x = 1
    y++;
    std::cout << "y = " << y << std::endl; // x = 2
}

#include <iostream>

void nullify(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n"); // ptr is non-null

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n"); // ptr is null
    return 0;
}