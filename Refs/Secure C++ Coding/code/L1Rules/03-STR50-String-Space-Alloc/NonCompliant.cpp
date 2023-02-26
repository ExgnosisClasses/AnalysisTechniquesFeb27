/*
Because the input is unbounded, the following code could lead to a buffer overflow.
*/

#include <iostream>

void f()
{
    char buf[12];
    std::cin >> buf;
}

/* 
To solve this problem, it may be tempting to use the std::ios_base::width() method, 
but there still is a trap, as shown in this noncompliant code example.
*/

#include <iostream>

void f()
{
    char bufOne[12];
    char bufTwo[12];
    std::cin.width(12);
    std::cin >> bufOne;
    std::cin >> bufTwo;
}

/* 
In this example, the first read will not overflow, but could fill bufOne with a truncated 
string. Furthermore, the second read still could overflow bufTwo.
*/