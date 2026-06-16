
/*Practice Task (From last lecture)

Update the program you previously wrote for Shape and its five derived classes to demonstrate
runtime polymorphism using virtual functions and override.
1. Modify the base class Shape so that it contains virtual functions input(), display(), and a
virtual destructor.
2. Each derived class (Rectangle, Triangle, Cylinder, Sphere, RegularPentagon) must override
input() and display() using the override keyword; in display() each class should print the
common color (by calling Shape::display() or printing it) and then print its own attributes
and computed results (area/perimeter for 2D shapes, volume/surface area for 3D shapes).
3. Keep the validation rule that all dimensions must be greater than 0.
4. In main(), do not call derived-class functions directly; instead, store objects of different
derived types using base-class pointers (or references) such as Shape* shapes[] (or a
dynamically allocated array of Shape*), call input() and display() through the base pointer
to show dynamic binding, and finally delete any dynamically allocated*/

#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

class shape
{
    string color;

public:
    shape()
    {
        color = "none";
    }
    virtual void input()
    {
        cout << "ENTER COLOR:";
        cin >> color;
    }
    virtual void display()
    {
        cout << "COLOR:" << color << endl;
    }
   virtual ~shape()
    {
        cout << "SHAPE DESTRUCTOR" << endl;
    }
};

class rectangle : public shape
{
    float length;
    float width;

public:
    rectangle()
    {
        length = 0;
        width = 0;
    }

    void input() override
    {
        shape::input();
        do
        {
            cout << "ENTER LENGTH:";
            cin >> length;
            cout << "ENTER WIDTH:";
            cin >> width;
        } while (length <= 0 || width <= 0);
    }

    float calc_perimeter()
    {
        return (2 * (length + width));
    }

    float calcrarea()
    {
        return length * width;
    }

    void display() override
    {
        cout << "FOR RECTANGLE" << endl;
        shape::display();
        cout << "AREA OF RECTANGLE IS:" << calcrarea() << endl;
        cout << "PERIMETER OF RECTANGLE IS:" << calc_perimeter() << endl;
    }

    ~rectangle()
    {
        cout << "DESTRUCTOR OF RECTANGLE" << endl;
    }
};

class triangle : public shape
{
    float base;
    float height;

public:
    triangle()
    {
        base = 0;
        height = 0;
    }

    void input() override
    {
        shape::input();
        do
        {
            cout << "ENTER BASE:";
            cin >> base;
            cout << "ENTER HEIGHT:";
            cin >> height;
        } while (base <= 0 || height <= 0);
    }

    void display()
    {
        cout << "FOR TRIANGLE" << endl;
        shape::display();
        cout << " BASE:" << base << endl;
        cout << "HEIGHT:" << height << endl;
        cout << "AREA OF TRIANGLE:" << calcarea() << endl;
    }

    float calcarea()
    {
        return (0.5 * (base * height));
    }

    ~triangle()
    {
        cout << "DESTRUCTOR OF TRIANGLE" << endl;
    }
};

class cylinder : public shape
{
    float radius;
    float height;

public:
    cylinder()
    {
        radius = 0;
        height = 0;
    }

    void input() override
    {
        cout << "FOR CYLINDER" << endl;
        shape::input();
        cout << "ENTER RADIUS:";
        cin >> radius;
        cout << "ENTER HEIGHT:";
        cin >> height;
    }

    void display() override
    {
        shape::display();
        cout << "HEIGHT:" << height << endl;
        cout << "RADIUS:" << radius << endl;
        cout << "AREA OF CYLINDER:" << calcarea() << endl;
    }

    float calcarea()
    {
        return ((2 * PI * ((radius * radius) + (radius * height))));
    }

    ~cylinder()
    {
        cout << "DESTRUCTOR OF CYLINDER" << endl;
    }
};

class sphere : public shape
{
    float radius;

public:
    sphere()
    {
        radius = 0;
    }

    void input() override
    {
        shape::input();
        cout << "ENTER RADIUS:";
        cin >> radius;
    }

    float calcarea()
    {
        return (4 * PI * radius * radius);
    }

    float calcvol()
    {
        return ((4.0 / 3.0) * PI * radius * radius * radius);
    }

    void display() override
    {
        shape::display();
        cout << "RADIUS:" << radius << endl;
        cout << "VOLUME:" << calcvol() << endl;
        cout << "AREA:" << calcarea() << endl;
    }

    ~sphere()
    {
        cout << "DESTRUCTOR OF SPHERE" << endl;
    }
};

class regularpentagon : public shape
{
    float side;

public:
    regularpentagon()
    {
        side = 0;
    }

    void input() override
    {
        shape::input();
        cout << "ENTER SIDE:";
        cin >> side;
    }

    float calcarea()
    {
        float a = (1.0 / 4.0) * sqrt(5 * (5 + 2 * (sqrt(5))) * side * side);
        return a;
    }

    float calc_perimeter()
    {
        return (5 * side);
    }

    void display() override
    {
        cout << "FOR REGULAR PENTAGON" << endl;
        shape::display();
        cout << "AREA:" << calcarea() << endl;
        cout << "PERIMETER:" << calc_perimeter() << endl;
    }

    ~regularpentagon()
    {
        cout << "DESTRUCTOR OF REGULAR PENTAGON" << endl;
    }
};
int main()
{
    shape *ptr[2];
    ptr[0] = new rectangle();
    ptr[1] = new triangle();
    ptr[2] = new cylinder();
    ptr[3] = new regularpentagon();
    ptr[4] = new sphere();
    for (int i = 0; i < 2; i++)
    {
        ptr[i]->input();
        ptr[i]->display();
    }
    for (int i = 0; i < 5; i++)
    {
        delete ptr[i];
    }
   

    return 0;
}