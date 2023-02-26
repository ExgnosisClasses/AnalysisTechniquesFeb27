/*
new and delete
In this compliant solution, the dynamically allocated memory 
is not deallocated until it is no longer required.
*/

#include <new>

struct S
{
    void f();
};

void g() noexcept(false)
{
    S *s = new S;
    // ...
    s->f();
    delete s;
}