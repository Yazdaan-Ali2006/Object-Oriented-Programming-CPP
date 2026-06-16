#include <iostream>
using namespace std;
class fraction
{
public:
    int den;
    int num;
    fraction(int den, int num)
    {
        this->num = num;
        this->den = den;
    }
    fraction add(fraction f1)
    {
        int newnum = (num * f1.den + f1.num * den);
        int newden = num * den;

        fraction ans(newnum, newden);
        return ans;
    }
    void display()
    {
        cout << num << " / " << den;
    }
};
1
int main()
{
    fraction f1(5, 2);

    f1.display();
    cout << endl;
    fraction f2(2, 5);
    f2.display();
    cout << endl;
    fraction f3 = f2.add(f1);
    f3.display();

    cout << endl;
    return 0;
}