#include <iostream>
using namespace std;
class course
{
    string name;

public:
    course(string a = "NULL") : name(a) {}
    void setcoursename(string n)
    {
        name = n;
    }
    void display()
    {
        cout <<"NAME"<< name<<endl;
    }
};
class student
{
    string student_name;
    course obj;

public:
    student(string s = "NULL")
    {
        student_name = s;
    
    }
    void enroll()
    {
        cout << "Student:" << student_name << endl;
        obj.display();
    }
};
int main()
{
    student s1("ali");
    s1.enroll();
    return 0;
}