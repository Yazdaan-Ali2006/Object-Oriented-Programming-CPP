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
    void input()
    {
        cout << "ENTER COURSE NAME:";
        cin >> name;
    }
};
class student
{
    string student_name;

public:
    student(string s = "NULL")
    {
        student_name = s;
    }
    void enroll(course *c)
    {
        cout << "Student:" << student_name << endl;
        c->input();
    }
};
int main()
{
    student s1("ali");
    course *c1;
    s1.enroll(c1);
    return 0;
}