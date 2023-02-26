/*
Because the library and application do not conform to the same ABI, this compliant 
solution modifies the library and application to work with a standard-layout type. 
Furthermore, it also adds a static_assert() to help guard against future code changes 
that accidentally modify S to no longer be a standard-layout type.
*/

// library.h
#include <type_traits>

struct S
{
    void f()
    { /* ... */
    } // No longer virtual
};
static_assert(std::is_standard_layout<S>::value, "S is required to be a standard layout type");

void func(S &s); // Implemented by the library, calls S::f()

// application.cpp
#include "library.h"

void g()
{
    S s;
    func(s);
}