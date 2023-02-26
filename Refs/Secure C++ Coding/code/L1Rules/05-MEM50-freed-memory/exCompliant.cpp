/*
std::unique_ptr
In this compliant solution, the lifetime of the buff object extends 
past the point at which the memory managed by the object is accessed.
*/

#include <iostream>
#include <memory>
#include <cstring>

int main(int argc, const char *argv[])
{
    const char *s = "";
    if (argc > 1)
    {
        enum
        {
            BufferSize = 32
        };
        try
        {
            std::unique_ptr<char[]> buff(new char[BufferSize]);
            std::memset(buff.get(), 0, BufferSize);
            // ...
            s = std::strncpy(buff.get(), argv[1], BufferSize - 1);
        }
        catch (std::bad_alloc &)
        {
            // Handle error
        }
    }

    std::cout << s << std::endl;
}