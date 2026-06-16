#include <iostream>
using namespace std;
 class Container
{
    int *ptr;

public:
    Container(int v)
    {
        ptr = new int(v);
    }
    void update(int v)
    {
        *ptr = v;
    }
    void show()
    {
        cout << *ptr << " ";
    }
};
int main()
{
    Container C1(10);
    Container C2 = C1;
    C2.update(50);
    C1.show();
    C2.show();
    return 0;
}