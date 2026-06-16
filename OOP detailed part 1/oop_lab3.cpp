#include <iostream>
using namespace std;
class student
{
    int roll;
    string name;

public:
    student()
    {
        roll = 0;
        name = "";
    }
    void set_roll()
    {
        cout << "Enter Roll No: ";
        cin >> roll;
    }
    void set_name()
    {
        cout << "Enter Name: ";
        cin >> name;
    }
    void display()
    {
        cout << "NAME: " << name << " ROLL No: " << roll << endl;
    }
};

int main()
{
    student c{};
    
    for (int i = 0; i < 2; i++)
    {
        c[i].set_name();
        c[i].set_roll();
    }
    for (int i = 0; i < 2; i++)
    {
          c[i].display();
    
    }

    return 0;
}