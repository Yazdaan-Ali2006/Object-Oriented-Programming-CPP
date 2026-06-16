#include <iostream>
using namespace std;

class a
{
public:
    static int count;

    a()
    {
        cout << "A constructor: " << count++ << endl;
    }
};

int a::count = 0;

class b : virtual public a
{
public:
    b()
    {
        cout << "B constructor" << endl;
    }
};

class c : virtual public a
{
public:
    c()
    {
        cout << "C constructor" << endl;
    }
};

class d : public c, public b
{
public:
    d()
    {
        cout << "D constructor" << endl;
    }
};

int main()
{
    d d1;
    return 0;
}