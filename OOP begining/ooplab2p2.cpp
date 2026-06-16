#include <iostream>
#include <cmath>

using namespace std;

class complex_number
{
public:
    int real;
    int imaginary;
    complex_number() // default constructor
    {
        real = 0;
        imaginary = 0;
    }

    complex_number(int a, int b) // parameterised constructor
    {
        real = a;
        imaginary = b;
    }
    complex_number(complex_number &c)
    {
        real = c.real;
        imaginary = c.imaginary;
    }
    void display()
    {
        cout << real << " + " << imaginary << "j" << endl;
    }
    float magnitude()
    {

        float add = (real * real) + (imaginary * imaginary);
        float final = sqrt(add);
        return final;
    }
};

int main()
{
    complex_number c1(2, 3);
    c1.display();
    complex_number c11(c1);
    cout << " " << magnitude(c1);

    return 0;
}