/*
placement new()
This compliant solution removes the call to ::operator delete(), 
allowing s1 to be destroyed as a result of its normal object lifetime termination.
*/

#include <iostream>

struct S
{
    S() { std::cout << "S::S()" << std::endl; }
    ~S() { std::cout << "S::~S()" << std::endl; }
};

void f()
{
    S s1;
    S *s2 = new (&s1) S;

    // ...
}