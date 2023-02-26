/*
In this compliant solution, the results from the call to std::getenv() 
are checked for null before the std::string object is constructed.
*/

#include <cstdlib>
#include <string>

void f()
{
    const char *tmpPtrVal = std::getenv("TMP");
    std::string tmp(tmpPtrVal ? tmpPtrVal : "");
    if (!tmp.empty())
    {
        // ...
    }
}