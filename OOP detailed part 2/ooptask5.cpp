#include <iostream>
using namespace std;
/*Design a ComplexNumber class with attributes for the real and
imaginary parts. Implement methods to add, subtract, multiply, and
display the complex numbers.*/
class complex_number
{
private:
    int real;
    int img;

public:
    complex_number()
    {
    }
    complex_number(int r , int i )
    {
        real = r;
        img = i;
    }
    void set_real(int r) // setter inline function
    {
        real = r;
    }
    void set_img(int i) // setter inline function
    {
        img = i;
    }
    int get_real() // getter inline function
    {
        return real;
    }
    int get_img() // getter inline functioninline function
    {
        return img;
    }
    complex_number add(complex_number a)
    {
        complex_number temp;
        temp.real = real + a.real;
        temp.img = img + a.img;
        return temp;
    }
    complex_number sub(complex_number a)
    {
        complex_number temp;
        temp.real = real - a.real;
        temp.img = img - a.img;
        return temp;
    }
    complex_number multiply(complex_number a)
    {
        complex_number temp;
        temp.real = (real * a.real)-(real * a.img);
        temp.img = (img * a.real) + (img * a.img);
        return temp;
    }

    void display();
};
void complex_number::display() // out_of_line function
{
    cout << get_real() << "+" << get_img() << "j" << endl;
}
int main()
{
    complex_number c1(2,3);
    complex_number c2(2,3);
    c1.display();
    c2.display();
    complex_number c3=c2.add(c1);
    c3.display();
    c3=c2.sub(c1);
    c3.display();
    c3=c2.multiply(c1);
    c3.display();
    return 0;
}
