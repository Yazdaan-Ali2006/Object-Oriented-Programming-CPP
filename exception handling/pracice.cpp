#include <iostream>
using namespace std;
class URS
{
    int age;
    int height;
    int salary;

public:
    URS()
    {
        age = 0;
        height = 0;
        salary = 0;
    }

    URS(int a, int h, int s)
    {
        age = a;
        height = h;
        salary = s;
    }
    void setage(int a)
    {
        age = a;
    }
    void setheight(int h)
    {
        height = h;
    }
    void setsalary(int s)
    {
        salary = s;
    }
    void display()
    {
        cout << "AGE:" << age << endl;
        cout << "HEIGHT:" << height << endl;
        cout << "SALARY:" << salary << endl;
    }
};

int main()
{
    int age;
    int salary;
    int height;
    URS obj;
    try
    {
        cout << "ENTER YOUR AGE:";
        cin >> age;
        if (age <= 0 || age >= 120)
        {
            throw("INVALID AGE EXCEPTION");
        }
        obj.setage(age);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    try
    {
        cout << "ENTER YOUR HEIGHT:";
        cin >> height;
        if (height <= 0)
        {
            throw("INVALID HEIGHT EXCEPTION");
        }
        obj.setheight(height);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    try
    {
        cout << "ENTER YOUR SALARY:";
        cin >> salary;
        if (salary <= 0)
        {
            throw("INVALID SALARY  EXCEPTION");
        }
        obj.setsalary(salary);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    cout<<"FINAL DATA"<<endl;
    obj.display();
    return 0;
}