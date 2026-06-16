#include <iostream>
using namespace std;
class vehicle
{
protected:
    float engine;
    string color;

public:
    vehicle(float e = 0.0, string c = "NONE")
    {
        engine = e;
        color = c;
    }
    virtual void display()
    {
        cout << "ENGINE:" << engine << endl;
        cout << "COLOR:" << color << endl;
    }
    ~vehicle(){
        cout<<"base"<<endl;
    }
};
class bike : public vehicle
{
protected:
    int footrest;

public:
    bike(float e, string c, int fr) : vehicle(e, c)
    {
        footrest = fr;
    }
    void display()
    {
        vehicle::display();
        cout << "NUMBER OF FOOT REST IN BIKE:" << footrest << endl;
    }
    ~bike(){
        cout<<"bike"<<endl;
    }
};
class car : public vehicle
{
protected:
    float trunk;

public:
    car(float e, string c, float tr) : vehicle(e, c)
    {
        trunk = tr;
    }
    void display()
    {
        vehicle::display();
        cout << "TRUNK CAPACITY IS" << trunk << "LITERS" << endl;
    }
    ~car(){
        cout<<"car"<<endl;
    }
};
int main()
{

    float engine;
    cout << "ENTER ENGINE CAPACITY IN CC" << endl;
    cin >> engine;
    string color;
    cout << "ENTER COLOR" << endl;
    cin >> color;
    float trunk;
    cout << "ENTER TRUNK CAPACITY IN LITERS" << endl;
    cin >> trunk;
    float footrest;
    cout << "ENTER NUM OF FOOTRESTS FOR BIKE" << endl;
    cin >> footrest;
    car c1(engine, color, trunk);
    bike b1(engine, color, footrest);
    vehicle *ptr[2];

    ptr[0] = &c1;
    ptr[1] = &b1;
    cout << "OUTPUT" << endl; // first car then bike
    ptr[0]->display();
    ptr[1]->display();

    return 0;
}