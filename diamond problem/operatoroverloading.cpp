#include <iostream>
using namespace std;
class complexnumber
{
public:
    int real;
    int img;
    complexnumber()
    {
        real = 0;
        img = 0;
    }
    complexnumber(int r, int i)
    {
        real = r;
        img = i;
    }
    complexnumber operator+(const complexnumber &c)
    {
        return complexnumber(real + c.real, img + c.img);
    }
    void display()
    {
        cout << real << "+" << img << "i" << endl;
    }
    // friend is used because left side is the not the [part of the class]
    // output
    friend ostream &operator<<(ostream &o, const complexnumber &c)
    {

        o << c.real << "+" << c.img << "i";
        return o;
    }
    // input
    friend istream &operator>>(istream &in, complexnumber &c)
    {
        cout << "Enter real part: ";
        in >> c.real;

        cout << "Enter imaginary part: ";
        in >> c.img;

        return in;
    }
    // prefix
    complexnumber &operator++()
    {
        real++;
        img++;
        return *this;
    }
    complexnumber operator++(int)
    {
        complexnumber temp = *this;
        real++;
        img++;
        return temp;
    }
};

int main()
{
    complexnumber c1(1, 2);
    complexnumber c2(1, 2);
    complexnumber c3(1, 2);
    complexnumber c4;
    c4 = c1 + c2 + c3;
    cout << "C4 AFTER SUM" << endl;
    cout << c4 << endl;
    cout << "C4 PREINCREMENT SUM" << endl;
    cout << ++c4 << endl;
    cout << "C4 POSTINCREMENT SUM" << endl;

    cout << c4++ << endl;
    cout << "C4 AFTER POSTINCREMENT SUM" << endl;

    cout << c4 << endl;
    complexnumber c5;
    cin >> c5;
    cout << c5 << endl;

    return 0;
}