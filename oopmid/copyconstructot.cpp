#include <iostream>
using namespace std;
class a
{
public:
    int *arr[3];
    string name;
    a()
    {
    }
    a(int *a[], string n)
    {
        for (int i = 0; i < 3; i++)
        {
            arr[i] = a[i];
        }
        name = n;
    }
    a(const a &obj)
    {
        for (int i = 0; i < 3; i++)
        {
            arr[i] = new int(*(obj.arr[i]));
        }
        name = obj.name;
    }
      void display(){
        cout<<"DSIPLAYING THE ARRAY"<<endl;
        for(int i=0;i<3;i++){
            cout<<*arr[i]<<endl;
        }
      }
    ~a()
    {
        for (int i = 0; i < 3; i++)
        {
            delete arr[i];
        }
        cout << "Destructor called and memory cleared" << endl;
    }
};
int main()
{
    int ab = 10;
    int b = 20;
    int c = 30;

    int *arrr[3] = {&ab, &b, &c};
    string n = "ali";
    a obj1(arrr, n);
    a obj2(obj1);
    obj1.display();
    *(obj2.arr[0])=100;
    obj2.display();
    

    return 0;
}