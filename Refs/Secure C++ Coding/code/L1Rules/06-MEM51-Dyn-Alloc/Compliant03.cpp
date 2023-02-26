/*
Double-Free
In this compliant solution, the copy constructor and copy assignment operator for C are explicitly deleted. 
This deletion would result in an ill-formed program with the definition of g() from the preceding 
noncompliant code example due to use of the deleted copy constructor. Consequently, g() 
was modified to accept its parameter by reference, removing the double-free.
*/

struct P
{
};

class C
{
    P *p;

public:
    C(P *p) : p(p) {}
    C(const C &) = delete;
    ~C() { delete p; }

    void operator=(const C &) = delete;

    void f() {}
};

void g(C &c)
{
    c.f();
}

void h()
{
    P *p = new P;
    C c(p);
    g(c);
}