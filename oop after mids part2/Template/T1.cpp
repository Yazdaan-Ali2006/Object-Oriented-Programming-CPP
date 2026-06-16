#include<iostream>
using namespace std;
template<class T>
class A
{public:
    T *arr
    T size;
    A(size)
    {
        arr=new T[10];
        cout<<"A()"<<endl;
    }
    ~A()
    {
        cout<<"~A()"<<endl;
    }
};
int main()
{
    return 0;
}