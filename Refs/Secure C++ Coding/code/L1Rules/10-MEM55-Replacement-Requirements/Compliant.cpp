/*
his compliant solution implements the required behavior for the replaced global allocator 
function by properly throwing a std::bad_alloc exception when the allocation fails.
*/

#include <new>

void *operator new(std::size_t size)
{
    extern void *alloc_mem(std::size_t); // Implemented elsewhere; may return nullptr
    if (void *ret = alloc_mem(size))
    {
        return ret;
    }
    throw std::bad_alloc();
}

void operator delete(void *ptr) noexcept;              // Defined elsewhere
void operator delete(void *ptr, std::size_t) noexcept; // Defined elsewhere