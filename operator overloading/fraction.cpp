#include <iostream>
using namespace std;
class fraction
{
    int den;
    int num;

public:
    fraction()
    {
        den = 0;
        num = 1;
    }
    fraction(int d, int n)
    {
        den = d;
        num = n;
    }
    fraction operator+(fraction f)
    {

        return fraction(((den * f.num) + (num * f.den)), (num * f.num));
    }
    fraction operator-(fraction f)
    {

        return fraction(((den * f.num) - (den * f.num)), (num * f.den));
    }
    friend ostream &operator<<(ostream &o, const fraction &f)
    {
        o << f.den << "/" << f.num << endl;
        return o;
    }
    friend istream &operator>>(istream &in, fraction &f)
    {
        cout << "ENTER DENOMINATOR" << endl;
        in >> f.den;
        cout << "ENTER NUMERATOR" << endl;
        in >> f.num;
        return in;

        return in;
    }
};
int main()
{
    // fraction f1(2, 5);
    fraction f1;
    cin >> f1;
    fraction f2;
    cin >> f2;

    // fraction f2(4, 6);
    cout << f1 + f2;
    return 0;
}