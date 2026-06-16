#include <iostream>
using namespace std;

class Shape
{
protected:
    float Area;

public:
    Shape()
    {
        Area = 0;
    }

    virtual void Calculate_Area() = 0;

    virtual void Display()
    {
        cout << "Area = " << Area << endl;
    }
};

// Derived Class Circle
class Circle : public Shape
{
private:
    float radius;

public:
    // Constructor
    Circle(float r)
    {
        radius = r;
    }

    void Calculate_Area()
    {
        Area = 3.1416 * radius * radius;
    }

    void Display()
    {
        cout << "Circle Area = " << Area << endl;
    }
};

class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    void Calculate_Area()
    {
        Area = length * breadth;
    }

    void Display()
    {
        cout << "Rectangle Area = " << Area << endl;
    }
};

int main()
{
    Shape *p;
    Circle C1(5);
    Rectangle R1(4, 6);
    p = &C1;
    p->Calculate_Area();
    p->Display();
    p = &R1;
    p->Calculate_Area();
    p->Display();

    return 0;
}