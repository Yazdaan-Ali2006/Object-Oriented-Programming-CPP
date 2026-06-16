#include <iostream>
using namespace std;
class dynamicarray
{
    int *data;
    int size;

public:
    dynamicarray(int s) : size(s)
    {
        data = new int[size];
        cout << "Constructor is working" << endl;
    }
    void setvalues(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            data[index] = value;
        }
    }
    int getvalue(int index)
    {
        if (index >= 0 && index < size)
        {
            return data[index];
        }
        else
        {
            return -1;
        }
    }
    ~dynamicarray(){
       delete data;
       cout<<"Destructor Called"<<endl;
    }
};
int main()
{   dynamicarray obj(5);
    obj.setvalues(0,1);
    obj.setvalues(1,2);
    obj.setvalues(2,3);
    obj.setvalues(3,4);
    cout<<obj.getvalue(3)<<endl;


    return 0;
}