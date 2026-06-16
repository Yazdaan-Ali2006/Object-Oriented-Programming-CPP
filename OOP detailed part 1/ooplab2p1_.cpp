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

    complex_number(complex_number &c) // copy constructor
    {
        real = c.real;
        imaginary = c.imaginary;
    }

    complex_number add(complex_number c) //addition
    {
        complex_number a;
        a.real = real + c.real;
        a.imaginary = imaginary + c.imaginary;
        return a;
    }
    float magnitude() //magnitude
    {
        float a = (float)real * real;
        float b = (float)imaginary * imaginary;
        float c = sqrt(a + b);
        return c;
    }
    void display() //display 
    {
        cout << real << " + " << imaginary << "j" << endl;
    }
};

int main()
{
    cout << "INITIALIZING:" << endl;
    complex_number c1(4, 3);
    cout<<"a= "; 
    c1.display();
  
    cout << "COPYING:" << endl;
    complex_number c2(c1);
    cout<<"b= ";
    c2.display();
  
    cout << "ADDTITION:" << endl;
    complex_number c3;
    c3=c2.add(c1);
    cout<<"a+b= ";
    c3.display();
  
    cout << "MAGNITUDE:" << endl;
    cout<<"|a|= ";
    cout<<" "<<c1.magnitude()<<endl;
    return 0;
}
