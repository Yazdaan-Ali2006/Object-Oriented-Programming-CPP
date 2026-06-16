#include <iostream>
using namespace std;
class a
{
public:
    virtual void method()
    {
        cout << "HELLO I AM A" << endl;
    }
};
class b : public a
{
public:
    void method() override
    {
        cout << "HELLO I AM B" << endl;
    }
};
class c : public a
{
public:
    void method() final
    {
        cout << "HELLO I AM C" << endl;
    };
};
class c1 : public c
{
public:
    void usemethod()
    {
        method();
    }
};
class d : public a
{
    void method() override
    {
        cout << "HELLO I AM d" << endl;
    };
};

int main()
{
    c1 obj;
    a *ptr = &obj;
    ptr->method();

    return 0;
}