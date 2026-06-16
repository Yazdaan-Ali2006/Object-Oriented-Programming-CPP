#include <iostream>
using namespace std;

class Parent {
public:
    int x;

    Parent() {
        x = 0;
        cout << "Parent constructor\n";
    }
};

class Child1 : public Parent {
public:
    Child1() {
        cout << "Child1 constructor\n";
    }
};

class Child2 : public Parent {
public:
    Child2() {
        cout << "Child2 constructor\n";
    }
};

class GrandChild : public Child1, public Child2 {
public:
    GrandChild() {
        cout << "GrandChild constructor\n";
    }

    void setValues() {
        Child1::x = 10;   
        Child2::x = 20;  
    }

    void showValues() {
        cout << "Child1::x = " << Child1::x << endl;
        cout << "Child2::x = " << Child2::x << endl;
    }
};

int main() {
    GrandChild obj;

    obj.setValues();
    obj.showValues();

    return 0;
}