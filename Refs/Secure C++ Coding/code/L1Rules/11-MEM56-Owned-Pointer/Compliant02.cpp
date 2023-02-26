/*
In this compliant solution, the dynamic_cast is replaced with a call to std::dynamic_pointer_cast(),
which returns a std::shared_ptr of the polymorphic type with the valid shared pointer value. 
When g() exits, the reference count to the underlying pointer is decremented by the destruction of 
derived, but because of the reference held by poly (within f()), the stored pointer value is still valid after g() returns
*/

#include <memory>

struct B
{
    virtual ~B() = default; // Polymorphic object
                            // ...
};
struct D : B
{
};

void g(std::shared_ptr<D> derived);

void f()
{
    std::shared_ptr<B> poly(new D);
    // ...
    g(std::dynamic_pointer_cast<D, B>(poly));
    // poly is still referring to a valid pointer value.
}