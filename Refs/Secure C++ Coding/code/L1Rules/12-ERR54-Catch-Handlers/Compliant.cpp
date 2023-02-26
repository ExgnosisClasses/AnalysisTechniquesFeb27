/*
In this compliant solution, the first handler catches all exceptions of class D, 
and the second handler catches all the other exceptions of class B.
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
    catch (D &d)
    {
        // ...
    }
    catch (B &b)
    {
        // ...
    }
}