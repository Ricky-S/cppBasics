#include <iostream>
#define FOO 0 // Here's a macro substitution


int add(int a, int b);

int main()
{
	int num { 2 }; // initialize num with the return value of getValueFromUserUB()
    int a = 4, b = 5;
	std::cout << add(a, b) << std::endl;
	std::cout << "Hello World!" << std::endl;

#ifndef FOO // This FOO does not get replaced because it’s part of another preprocessor directive
    std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
#endif
	return 0;
}