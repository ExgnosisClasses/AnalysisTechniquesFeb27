/*
std::string::c_str()
In this compliant solution, a local copy of the string returned by str_func() is 
made to ensure that string str will be valid when the call to display_string() is made.
*/

#include <string>

std::string str_func();
void display_string(const char *s);

void f()
{
    std::string str = str_func();
    const char *cstr = str.c_str();
    display_string(cstr); /* ok */
}