/*
The amount of overhead required by array new expressions is unspecified but ideally would be 
documented by quality implementations. The following compliant solution is specifically for 
the Clang and GNU GCC compilers, which guarantee that the overhead for dynamic array allocations 
is a single value of type size_t. To verify that the assumption is, in fact, safe, the 
compliant solution also overloads the pl    acement new[] operator to accept the buffer size as a 
third argument and verifies that it is not smaller than the total amount of storage required.
*/

#include <cstddef>
#include <new>

#if defined(__clang__) || defined(__GNUG__)
const size_t overhead = sizeof(size_t);
#else
static_assert(false, "you need to determine the size of your implementation's array overhead");
const size_t overhead = 0; // Declaration prevents additional diagnostics about overhead being undefined; the value used does not matter.
#endif

struct S
{
    S();
    ~S();
};

void *operator new[](size_t n, void *p, size_t bufsize)
{
    if (n > bufsize)
    {
        throw std::bad_array_new_length();
    }
    return p;
}

void f()
{
    const size_t n = 32;
    alignas(S) unsigned char buffer[sizeof(S) * n + overhead];
    S *sp = ::new (buffer, sizeof(buffer)) S[n];

    // ...
    // Destroy elements of the array.
    for (size_t i = 0; i != n; ++i)
    {
        sp[i].~S();
    }
}