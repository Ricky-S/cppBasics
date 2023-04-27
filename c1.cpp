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

    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x
    int* ptr {}; // ptr is a null pointer, and is not holding an address
    ptr = &x; // ptr now holds the address of x
    *ptr = 6; 
    std::cout << x << '\n'; // print the value of variable x

    return 0;

}