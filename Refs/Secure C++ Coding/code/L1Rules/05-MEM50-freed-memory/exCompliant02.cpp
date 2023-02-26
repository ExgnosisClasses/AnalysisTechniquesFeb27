/*
Automatic Storage Duration
In this compliant solution, a variable with automatic storage duration of type std::string 
is used in place of the std::unique_ptr<char[]>, which reduces the complexity and improves 
the security of the solution.
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