#include <iostream>
using namespace std;
class student
{
    string name;
    float gpa;

public:
    student(string n = "", float g = 0)
    {
        gpa = g;
        name = n;
    }
    bool operator==(student s1)
    {
        return (this->gpa == s1.gpa);
    }
    bool operator!=(student s1)
    {
        return (this->gpa != s1.gpa);
    }
    bool operator>(student s1)
    {
        return (this->gpa > s1.gpa);
    }
    friend ostream &operator<<(ostream &o, student s1)
    {
        o << "NAME:" << s1.name << endl;
        o << "GPA:" << s1.gpa << endl;
    }
};
int main()
{
    student s1("ali", 3.96);
    student s2("haider", 3.96);
    cout << s1;
    cout << s2;
    if (s1 == s2)
    {
        cout << "GPA ARE EQUAL" << endl;
    }
    else if (s1 > s2)
    {
        cout << "GPA OF STUDENT 1 IS HIGHER" << endl;
    }

    return 0;
}