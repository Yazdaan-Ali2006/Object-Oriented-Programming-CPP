#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A constructor\n"; }
    ~A() { cout << "A destructor\n"; }
};

class B
{
public:
    B() { cout << "B constructor\n"; }
    ~B() { cout << "B destructor\n"; }
};

class C
{
public:
    C() { cout << "C constructor\n"; }
    ~C() { cout << "C destructor\n"; }
};

class D : public A, public B
{
    C c1;
    C c2;
public:
    D() { cout << "D constructor\n"; }
    ~D() { cout << "D destructor\n"; }
};

int main()
{   /*
    CONSTRUTOR
    A
    B
    C(2 TIMES)
    D

   DESTRUCTOR
    D
    C(2 TIMES)
    B
    A
    */
    D obj;
}