#include <iostream>
#define PI 3.14
using namespace std;
class shape
{
protected:
    float area;

public:
    shape()
    {
        area = 0;
    }
    shape(float area)
    {
        this->area = area;
    }
    float getarea()
    {
        return area;
    }
    void setarea(float a)
    {
        area = a;
    }
    void virtual display()
    {
        cout << "AREA =" << calculate_area() << endl;
    }
    virtual float calculate_area() = 0;
};
class rectangle : public shape
{
private:
    float length;
    float breadth;

public:
    rectangle(float l = 0, float b = 0)
    {
        length = l;
        breadth = b;
    }
    float calculate_area() override
    {
        return length * breadth;
    }
    void display() override
    {
        cout << "Rectangle Area = " << calculate_area() << endl;
    }
};
class circle : public shape
{
private:
    float radius;

public:
    circle(float r = 0)
    {
        radius = r;
    }
    float calculate_area() override
    {
        return PI * radius * radius;
    }
    void display() override
    {
        cout << "Circle Area = " << calculate_area() << endl;
    }
};
class triangle : public shape
{
private:
    float base;
    float height;

public:
    triangle(float b = 0, float h = 0)
    {
        base = b;
        height = h;
    }
    void setbase(float b)
    {
        base = b;
    }
    void setheight(float h)
    {
        height = h;
    }
    float getheight()
    {
        return height;
    }
    float getbase()
    {
        return base;
    }
    float calculate_area() override
    {
        return 0.5 * base * height;
    }

    void display() override
    {
        cout << "Triangle Area = " << calculate_area() << endl;
    }
};
int main()
{    shape* array[3];
      array[0]=new circle(10);
      array[1]=new triangle(20,10);
      array[2]=new rectangle(15,18);
      float maxarea=array[0]->calculate_area();
      int index=0;
      int i;
      for( i=0;i<3;i++){
        array[i]->display();
        if(array[i]->calculate_area()>maxarea){
           maxarea=array[i]->calculate_area();
           index=i;
        }
      }
    cout<<"THE MAXIMUM AREA:"<<endl;
     array[index]->display();
     
    for(int i=0;i<3;i++){
        delete array[i];
    }
    return 0;
}