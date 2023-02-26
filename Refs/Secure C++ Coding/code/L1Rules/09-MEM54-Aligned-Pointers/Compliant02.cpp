/*
This compliant solution ensures that the long is constructed into a buffer of 
sufficient size and with suitable alignment.
*/

#include <new>

void f()
{
    char c; // Used elsewhere in the function
    std::aligned_storage<sizeof(long), alignof(long)>::type buffer;
    long *lp = ::new (&buffer) long;

    // ...
}