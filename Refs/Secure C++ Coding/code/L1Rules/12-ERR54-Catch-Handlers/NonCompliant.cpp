/*
In this noncompliant code example, the first handler catches all exceptions of class B, 
as well as exceptions of class D, since they are also of class B. Consequently, the second 
handler does not catch any exceptions.
*/

// Classes used for exception handling
class B
{
};
class D : public B
{
};

void f()
{
    try
    {
        // ...
    }
    catch (B &b)
    {
        // ...
    }
    catch (D &d)
    {
        // ...
    }
}