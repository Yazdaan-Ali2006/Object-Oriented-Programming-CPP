#include <iostream>
using namespace std;
/* Develop a Car class that contains attributes like make, model, year, and
speed. Include methods like accelerate and brake.*/
class car
{
    string make;
    string model;
    int year;
    float speed;
    public:
    car(string mk = "unknown", string mo = "unknown", int yr = 0, int spd = 0)
    {
        make = mk;
        model = mo;
        year = yr;
        speed = spd;
    }
    void set_make(string a)
    {
        make = a;
    }
    void set_model(string a)
    {
        model = a;
    }
    void set_year(int a)
    {
        year = a;
    }

    void set_speed(float a)
    {
        speed = a;
    }
    string get_make()
    {
        return make;
    }
    string get_model()
    {
        return model;
    }
    float get_speed()
    {
        return speed;
    }
    int get_year()
    {
        return year;
    }
    void accelerate(float a);
    void braking(float a);
    void display();
};
void car::accelerate(float a)
{
    speed += a;
}
void car::braking(float a)
{
    if (a > speed)
    {
        cout << "Invalid BRAKING!!" << endl;
    }
    else
    {
        speed -= a;
    }
}
void car::display()
{
    cout << "MAKE: " << get_make() << endl;
    cout << "MODEL: " << get_model() << endl;
    cout << "YEAR: " << get_year() << endl;
    cout << "SPEED: " << get_speed() << endl;
}
int main()
{
    car c1("Honda", "City", 2007, 120);
    c1.accelerate(20);
    c1.braking(150);
    c1.display();
    return 0;
}