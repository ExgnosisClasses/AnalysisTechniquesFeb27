/*
In this noncompliant code example, a pointer to a short is passed to placement new, 
which is attempting to initialize a long. On architectures where sizeof(short) < sizeof(long), 
this results in undefined behavior. 
*/

#include <new>

void f()
{
    short s;
    long *lp = ::new (&s) long;
}