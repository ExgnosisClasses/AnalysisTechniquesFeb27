/* In this noncompliant code example, a random access iterator from a std::vector is used in an additive expression, 
   but the resulting value could be outside the bounds of the container rather than a past-the-end value.
*/
#include <iostream>
#include <vector>

void f(const std::vector<int> &c)
{
    for (auto i = c.begin(), e = i + 20; i != e; ++i)
    {
        std::cout << *i << std::endl;
    }
}