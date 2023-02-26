/*
In this compliant solution, the std::shared_ptr objects are related to one another through 
copy construction. When the local, automatic variable p2 is destroyed, the use count for 
the shared pointer value is decremented but still nonzero. Then, when the local, automatic 
variable p1 is destroyed, the use count for the shared pointer value is decremented to zero, 
and the managed pointer is destroyed. This compliant solution also calls std::make_shared() 
instead of allocating a raw pointer and storing its value in a local variable.
*/

#include <memory>

void f()
{
    std::shared_ptr<int> p1 = std::make_shared<int>();
    std::shared_ptr<int> p2(p1);
}