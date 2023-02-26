/*
When using std::nothrow, the new operator returns either a null pointer or a pointer to the 
allocated space. Always test the returned pointer to ensure it is not nullptr before referencing 
the pointer. This compliant solution handles the error condition appropriately when the 
returned pointer is nullptr
*/

#include <cstring>
#include <new>

void f(const int *array, std::size_t size) noexcept
{
    int *copy = new (std::nothrow) int[size];
    if (!copy)
    {
        // Handle error
        return;
    }
    std::memcpy(copy, array, size * sizeof(*copy));
    // ...
    delete[] copy;
}