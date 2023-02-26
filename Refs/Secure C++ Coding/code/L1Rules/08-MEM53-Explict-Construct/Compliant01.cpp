/*
In this compliant solution, the constructor and destructor are both explicitly called. 
Further, to reduce the possibility of the object being used outside of its lifetime, 
the underlying storage is a separate variable from the live object.
*/

#include <cstdlib>
#include <new>

struct S
{
    S();

    void f();
};

void g()
{
    void *ptr = std::malloc(sizeof(S));
    S *s = new (ptr) S;

    s->f();

    s->~S();
    std::free(ptr);
}