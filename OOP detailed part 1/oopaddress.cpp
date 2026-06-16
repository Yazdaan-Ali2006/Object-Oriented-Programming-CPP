#include <iostream>
using namespace std;
class example
{
public:
    int val;
    int ref;

    example()
    {
    }

    example(int v, int r)
    {
        cout << "value=" << v << "" << "ref=" << r << endl;
    }
};
int main()
{
    int num = 10;
    example ex(5, num);
    cout << "value =" << ex.val << endl;
    cout << "ref =" << ex.ref << endl;
    int a = 10;
    int &x = a; // shallow copy banadega
    int *ptr = &a;
     

    /*  cout << "&a=" << &a << endl;
      cout << "x=" << x << endl;
      cout << "&x=" << &x << endl;
      cout << "ptr=" << ptr << endl;
      cout << "*(ptr)=" << *(ptr) << endl;
      cout << "&ptr=" << &ptr << endl;*/

    return 0;
}