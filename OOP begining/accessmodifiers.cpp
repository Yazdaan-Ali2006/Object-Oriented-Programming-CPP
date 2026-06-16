#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int age;

private:
    int roll_no;

public:
    student()
    {
        // default constructor
    }
    // my own constructor
    student(string name, int roll_no, int age)
    {
        this->name = name;
        this->roll_no = roll_no;
        this->age = age;
    }
    // display
    void display()
    {
        cout << "NAME:    " << name << "\n";
        cout << "AGE:     " << age << "\n";
        cout << "ROLL NO: " << roll_no << "\n";
    }
};
int main()
{
    student s1("Ali", 30, 19);
    s1.display();


    return 0;
}