/*
In this noncompliant code example, two memory allocations are performed within the same expression. 
Because the memory allocations are passed as arguments to a function call, an exception 
thrown as a result of one of the calls to new could result in a memory leak.
*/

#include <cstring>

void f(const int *array, std::size_t size) noexcept
{
    int *copy = new int[size];
    std::memcpy(copy, array, size * sizeof(*copy));
    // ...
    delete[] copy;
}