/*
If the design of the function is such that the caller is expected to handle 
exceptional situations, it is permissible to mark the function explicitly 
as one that may throw, as in this compliant solution. Marking the function is 
not strictly required, as any function without a noexcept specifier is presumed to allow throwing.
*/

#include <cstring>

void f(const int *array, std::size_t size) noexcept(false)
{
    int *copy = new int[size];
    // If the allocation fails, it will throw an exception which the caller
    // will have to handle.
    std::memcpy(copy, array, size * sizeof(*copy));
    // ...
    delete[] copy;
}