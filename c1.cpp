#include "dbg.h"
#include <iostream>

// #define FOO 0 // Here's a macro substitution


int add(int a, int b);

int main()
{
	int num { 2 }; // initialize num with the return value of getValueFromUserUB()
    int a = 4, b = 5;
	std::cerr << "Error: " << num << std::endl;
	std::cout << dbg(add(a, b)) << std::endl;
	std::cout << (add(a, 56)) << std::endl;
	std::cout << "Hello 23World!" << std::endl;
	std::cout << "He2342342d!" << std::endl;

	#include <iostream>


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

    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65537; // 65536 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    x = -1; // 65536 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';
// #ifndef FOO // This FOO does not get replaced because it’s part of another preprocessor directive
//     std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
// #endif
	return 0;
}