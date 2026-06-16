#include <iostream>
using namespace std;
class first
{
public:
    int age;
    first(int a = 0)
    {
        age = a;
    }
    ~first(){
    cout<<"first dest..."<<endl;
}
};
class second
{
    string n;

public:
    second(string a = "null")
    {
        n = a;
    }
    void display(first*s1){
        cout<<"AGE:"<<s1->age<<endl;
        cout<<"NAME:"<<n<<endl;
    }
    ~second(){
        cout<<"sec dest..."<<endl;
    }
};
int main()
{  
    first s1(10);
    second s2("apple");
    s2.display(&s1);
    return 0;
}