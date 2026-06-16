#include <iostream>
using namespace std;

class X
{
public:
    X() { cout << "X constructor" << endl; }
    ~X() { cout << "X destructor" << endl; }
};

class Y
{
public:
    Y() { cout << "Y constructor" << endl; }
    ~Y() { cout << "Y destructor" << endl; }
};

class Z : public X
{
    Y y;
public:
    Z() { cout << "Z constructor" << endl; }
    ~Z() { cout << "Z destructor" << endl; }
};

int main()
{ 
    Z obj;
    
       
}