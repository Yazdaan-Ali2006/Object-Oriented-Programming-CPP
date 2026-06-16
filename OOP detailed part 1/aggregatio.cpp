#include <iostream>
using namespace std;
class a
{
public:
    int a;
    void print()
    {
        cout << "CLASS A" << endl;
    }
    ~ a(){
        cout<<"DESTRUCTOR OF A"<<endl;
    }
};
class b
{ public:
    int b;
    a* obj;
    void print(a*object)
    {   obj=object;
        obj->print();
        cout << "CLASS B" << endl;
    }
    ~ b(){
        cout<<"DESTRUCTOR OF B"<<endl;
    }
};

int
main()
{
    a obj1;
    b obj;
    obj.print(&obj1);
    cout<<"hello world"<<endl;
    return 0;
}