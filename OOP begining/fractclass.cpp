#include <iostream>
using namespace std;
class fraction
{  private:
    int den;
    int num;
    public:
    fraction(int a, int b)
    {
        num = a;
        den = b;
    }
    fraction operator +(fraction f1)
    {
        int newn = num * f1.den + den * f1.num;
        int newd = den * f1.den
        fraction ans(newn, newd);
        return ans;
    }
    void display()
    {
        cout<<num<<" / "<<den<<endl;
    } 
};
int main()
{
    fraction f1(1, 2);
    f1.display();
    fraction f2(1, 2);
    f2.display();
    fraction f3=f1+f2;
    f3.display();
    
    return 0;
}