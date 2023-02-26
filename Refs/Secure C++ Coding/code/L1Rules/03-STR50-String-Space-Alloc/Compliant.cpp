/*
The best solution for ensuring that data is not truncated and for guarding against buffer 
overflows is to use std::string instead of a bounded array, as in this compliant solution
*/

#include <iostream>
#include <string>

void f()
{
    std::string input;
    std::string stringOne, stringTwo;
    std::cin >> stringOne >> stringTwo;
}
