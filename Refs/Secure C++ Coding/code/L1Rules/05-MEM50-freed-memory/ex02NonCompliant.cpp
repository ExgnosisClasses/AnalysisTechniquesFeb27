/*
std::string::c_str()
In this noncompliant code example, std::string::c_str() is being called on a temporary std::string object. 
The resulting pointer will point to released memory once the std::string object is destroyed at the 
end of the assignment expression, resulting in undefined behavior when accessing elements of that pointer.
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