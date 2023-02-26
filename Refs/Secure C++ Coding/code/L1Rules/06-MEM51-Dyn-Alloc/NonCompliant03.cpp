/*
Double-Free
Once a pointer is passed to the proper deallocation function, that pointer value is invalidated. 
Passing the pointer to a deallocation function a second time when the pointer value has not been 
returned by a subsequent call to an allocation function results in an attempt to free memory
 that has not been allocated dynamically. The underlying data structures that manage the heap
 can become corrupted in a way that can introduce security vulnerabilities into a program. 
 These types of issues are called double-free vulnerabilities. In practice, double-free vulnerabilities 
 can be exploited to execute arbitrary code.
*/

struct P
{
};

class C
{
    P *p;

public:
    C(P *p) : p(p) {}
    ~C() { delete p; }

    void f() {}
};

void g(C c)
{
    c.f();
}

void h()
{
    P *p = new P;
    C c(p);
    g(c);
}