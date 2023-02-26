/*
TIn this compliant solution, the alignas declaration specifier is used to ensure the buffer 
is appropriately aligned for a long.
*/

#include <new>

void f()
{
    char c; // Used elsewhere in the function
    alignas(long) unsigned char buffer[sizeof(long)];
    long *lp = ::new (buffer) long;

    // ...
}