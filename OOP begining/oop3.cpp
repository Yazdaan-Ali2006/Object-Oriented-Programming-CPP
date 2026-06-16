#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    int roll_no;
    int age;
    Student()
    { // default constructor
    }

    Student(string Name, int Roll_no, int Age)
    { // paramaterised constructor
        name = Name;
        roll_no = Roll_no;
        age = Age;
    }
    void printdata()
    {
        cout << name << " " << roll_no << " " << age << endl;
    }
};
changename(Student *s)
{ // object pointer
    (*s).name = "zia";
}

int main()
{
    Student s1("Yazdaan Ali", 30, 19);
    changename(&s1);
    s1.printdata();

    return 0;
}