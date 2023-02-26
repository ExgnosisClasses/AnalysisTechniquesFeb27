/*
The compliant solution is to use std::enable_shared_from_this::shared_from_this() to get a shared 
pointer from S that is related to an existing std::shared_ptr object. A common 
implementation strategy is for the std::shared_ptr constructors to detect the 
presence of a pointer that inherits from std::enable_shared_from_this, and automatically 
update the internal bookkeeping required for std::enable_shared_from_this::shared_from_this() 
to work. Note that std::enable_shared_from_this::shared_from_this() requires an existing 
std::shared_ptr instance that manages the pointer value pointed to by this. Failure to 
meet this requirement results in undefined behavior, as it would result in a smart pointer 
attempting to manage the lifetime of an object that itself does not have lifetime management semantics.
*/

#include <memory>

struct S : std::enable_shared_from_this<S>
{
    std::shared_ptr<S> g() { return shared_from_this(); }
};

void f()
{
    std::shared_ptr<S> s1 = std::make_shared<S>();
    std::shared_ptr<S> s2 = s1->g();
}