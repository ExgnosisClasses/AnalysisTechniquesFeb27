/*
When possible, the more resilient compliant solution is to remove the 
memory allocation entirely and pass the objects by reference instead.
*/

#include <memory>

struct A
{ /* ... */
};
struct B
{ /* ... */
};

void g(A &a, B &b);
void f()
{
    A a;
    B b;
    g(a, b);
}