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
    { // constructor
        name = Name;
        roll_no = Roll_no;
        age = Age;
    }
};

void print(Student s1)
{
    cout << s1.name << " " << s1.roll_no << " " << s1.age << endl;
}
int main()
{
    Student s1("Yazdaan Ali", 30, 19);
    print(s1);

    return 0;
}