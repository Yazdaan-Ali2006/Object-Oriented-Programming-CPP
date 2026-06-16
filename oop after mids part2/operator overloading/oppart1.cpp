#include <iostream>
using namespace std;
class complexnumber
{
private:
    float real;
    float img;

public:
    complexnumber()
    {
        real = 0;
        img = 0;
    }
    complexnumber(float a, float b)
    {
        real = a;
        img = b;
    }

    complexnumber operator+(complexnumber c1)
    {
        return complexnumber(real + c1.real, img + c1.img);
    }
    complexnumber operator-(complexnumber c1)
    {
        return complexnumber(real - c1.real, img - c1.img);
    }
    complexnumber operator*(complexnumber c1)
    {
        return complexnumber((real * c1.real) - (img * c1.img), (img * c1.img) + (real * c1.img));
    }
    complexnumber operator++()
    {
        real++;
        img++;
        return *this;
    }
    complexnumber operator++(int x)
    {
        complexnumber temp = *this;
        real++;
        img++;
        return temp;
    }

    friend ostream &operator<<(ostream &o, const complexnumber &c1)
    {
        o << c1.real << "+" << c1.img << "i" << endl;
        return o;
    }
    friend istream &operator>>(istream &i, complexnumber &c1)
    {
        cout << "ENTER REAL NUMBER" << endl;
        i >> c1.real;
        cout << "ENTER IMAGINARY NUMBER" << endl;
        i >> c1.img;
        return i;
    }

    bool operator==(const complexnumber &c1)
    {
        if ((real == c1.real) && (img == c1.img))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    complexnumber c1;
    complexnumber c2;
    cin >> c1;
    cin >> c2;
    complexnumber c3;

    c3 = c1 + c2;

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    if (c1 == c2)
    {
        cout << "EQUAL" << endl;
    }
    else
    {
        cout << "UNEQUAL" << endl;
    }

    cout << ++c3 << endl;
    cout << c3++ << endl;

    return 0;
}