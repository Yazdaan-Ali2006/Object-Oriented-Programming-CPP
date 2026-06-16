#include <iostream>
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
    void display()
    {
        cout << real << " + " << imaginary << "j";
    }
};

int main()
{
    complex_number c1(2, 3);
    c1.display();

    return 0;
}