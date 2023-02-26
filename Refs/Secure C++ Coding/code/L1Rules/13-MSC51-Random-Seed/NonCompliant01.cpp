/*
This noncompliant code example generates a sequence of 10 pseudorandom numbers using the 
Mersenne Twister engine. No matter how many times this code is executed, it always produces 
the same sequence because the default seed is used for the engine.
*/

#include <random>
#include <iostream>

void f()
{
    std::mt19937 engine;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << engine() << ", ";
    }
}