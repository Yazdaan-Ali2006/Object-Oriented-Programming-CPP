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
    void input()
    {
        cout << "ENTER COLOR:";
        cin >> color;
    }
    void display()
    {
        cout << "COLOR:" << color << endl;
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

    void input()
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
    void display()
    {
        cout << "FOR RECTANGLE" << endl;
        shape::display();
        cout << "AREA OF RECTANGLE IS:" << calcrarea() << endl;
        cout << "PERIMETER OF RECTANGLE IS:" << calc_perimeter() << endl;
    }
};
/*Triangle (attributes: base, height; methods: input (), cal_area(), display ()),*/
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
    void input()
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
    void input()
    {
        cout << "FOR CYLINDER" << endl;
        shape::input();
        cout << "ENTER RADIUS:";
        cin >> radius;
        cout << "ENTER HEIGHT:";
        cin >> height;
    }
    void display()
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
};
/*Sphere (attribute: radius; methods: input(), cal_volume(), cal_surfaceArea(), display()), and*/
class sphere : public shape
{
    float radius;

public:
    sphere()
    {
        radius = 0;
    }
    void input()
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
    void display()
    {
        shape::display();
        cout << "RADIUS:" << radius << endl;
        cout << "VOLUME:" << calcvol() << endl;
        cout << "AREA:" << calcarea() << endl;
    }
};
/*Sphere (attribute: radius; methods: input(), cal_volume(), cal_surfaceArea(), display()), and*/
class regularpentagon : public shape
{
    float side;

public:
    regularpentagon()
    {
        side = 0;
    }
    void input()
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
    void display()
    {
        cout << "FOR REGULAR PENTAGON" << endl;
        shape::display();
        cout << "AREA:" << calcarea() << endl;
        cout << "PERIMETER:" << calc_perimeter() << endl;
    }
};
int main()
{
    cout << "============================================" << endl;
    cout << "=================RECTANGLE==================" << endl;
    cout << "============================================" << endl;
    rectangle c1;
    c1.input();
    c1.display();
    cout << "==============================================" << endl;
    cout << "\n";
    rectangle t1;
    cout << " ============================================" << endl;
    cout << "==================TRIANGLE==================" << endl;
    cout << "============================================" << endl;
    t1.input();
    t1.display();
    cout << "===============================================" << endl;
    cout << "\n";
    cylinder p1;
    cout << "============================================" << endl;
    cout << "==================CYLINDER==================" << endl;
    cout << "============================================" << endl;
    p1.input();
    p1.display();
    cout << "============================================" << endl;
    cout << "\n";
    regularpentagon r1;
    cout << "============================================" << endl;
    cout << "================REGULAR PENTAGON============" << endl;
    cout << "============================================" << endl;
    r1.input();
    r1.display();
    cout << "==============================================" << endl;

    return 0;
}