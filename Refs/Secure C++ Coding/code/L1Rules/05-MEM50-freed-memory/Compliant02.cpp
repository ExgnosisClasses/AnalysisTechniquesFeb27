/*
Automatic Storage Duration
When possible, use automatic storage duration instead of dynamic storage duration. 
Since s is not required to live beyond the scope of g(), this compliant solution 
uses automatic storage duration to limit the lifetime of s to the scope of g().
*/

struct S
{
    void f();
};

void g()
{
    S s;
    // ...
    s.f();
}