#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int age;

    student()
    {
        name = "null";
        age = 0;
    }
    student(string n, int a)
    {
        name = n;
        age = a;
    }
    ~student()
    {
        cout << "I am student destructor" << endl;
    }
};
class subject
{
public:
    student s1;
    string sub;

    subject(string s, string n, int a) : s1(n, a)
    {
        sub=s;
    }
    void display()
    {
        cout << "NAME:" << s1.name << endl;
        cout << "AGE:" << s1.age << endl;
        cout << "SUBJECT:" << sub << endl;
    }
    ~subject()
    {
        cout << "i am base destructor" << endl;
    }
};
int main()
{
    subject s1("maths", "ali", 10);
    s1.display();
    return 0;
} 
/*

student constructor
subject constructor
display function
subject destructor
student destructor

*/