/* This compliant solution assumes that the programmer's intention was to process up to 20 items in the container. 
    Instead of assuming all containers will have 20 or more elements, the size of the container is used to determine 
    the upper bound on the addition.
*/
#include <algorithm>
#include <vector>

void f(const std::vector<int> &c)
{
    const std::vector<int>::size_type maxSize = 20;
    for (auto i = c.begin(), e = i + std::min(maxSize, c.size()); i != e; ++i)
    {
        // ...
    }
}