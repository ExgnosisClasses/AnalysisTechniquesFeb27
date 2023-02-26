/*
This noncompliant code example assumes that there is a library whose header is library.h, 
an application (represented by application.cpp), and that the library and application are 
not ABI-compatible. Therefore, the contents of library.h constitute an execution boundary. 
A nonstandard-layout type object S is passed across this execution boundary. The 
application creates an instance of an object of this type, then passes a reference to the 
object to a function defined by the library, crossing the execution boundary. Because 
the layout is not guaranteed to be compatible across the boundary, this results in unexpected behavior.
*/

// library.h
struct S
{
    virtual void f()
    { /* ... */
    }
};

void func(S &s); // Implemented by the library, calls S::f()

// application.cpp
#include "library.h"

void g()
{
    S s;
    func(s);
}