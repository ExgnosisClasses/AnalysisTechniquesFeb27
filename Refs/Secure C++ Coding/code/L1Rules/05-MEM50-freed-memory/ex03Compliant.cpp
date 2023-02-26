/*
The compliant solution depends on programmer intent. If the programmer intends 
to allocate a single unsigned char object, the compliant solution is to use new 
instead of a direct call to operator new(), as this compliant solution demonstrates. 
*/

void f() noexcept(false)
{
    unsigned char *ptr = new unsigned char;
    *ptr = 0;
    // ...
    delete ptr;
}

/*
If the programmer intends to allocate zero bytes of memory (perhaps to obtain 
a unique pointer value that cannot be reused by any other pointer in the program
until it is properly released), then instead of attempting to dereference the 
resulting pointer, the recommended solution is to declare ptr as a void *, 
which cannot be dereferenced by a conforming implementation.
 
*/

#include <new>

void f() noexcept(false)
{
    void *ptr = ::operator new(0);
    // ...
    ::operator delete(ptr);
}