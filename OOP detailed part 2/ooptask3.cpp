#include <iostream>
using namespace std;
/*3. Create a Student class with attributes like name, rollNumber, and marks.
Implement methods to calculate the grade based on the marks.*/
class Student
{
    string name;
    int roll_num;
    float marks[3];

public:
    Student(string n = "null", int r = 0, float m = 0)

    {
        name = n;
        roll_num = r;
        marks[0] = marks[1] = marks[2] = m;
    }

} void set_name(string a)
{
    name = a;
}
string get_name()
{
    return name;
}
void set_roll(int a)
{
    roll_num = a;
}
int get_roll()
{
    return roll_num;
}
void set_marks(float a, float b, float c)
{
    marks[0] = a;
    marks[1] = b;
    marks[2] = c;
}
float get_m1()
{
    return marks[0];
}
float get_m2()
{
    return marks[1];
}
float get_m3()
{
    return marks[2];
}
void grade();
void display();
}
;
void Student::grade()
{
    float percentage = ((marks[0] + marks[1] + marks[2]) / 300) * 100;
    if (percentage >= 80)
    {
        cout << "Grade: A-1" << endl;
    }
    else if (percentage >= 70)
    {
        cout << "Grade:A" << endl;
    }
    else if (percentage >= 60)
    {
        cout << "Grade: B" << endl;
    }
    else if (percentage >= 50)
    {
        cout << "Grade: C" << endl;
    }
    else
    {
        cout << "Fail!" << endl;
    }
}
void Student::display()
{
    cout << "Name: " << get_name() << endl;
    cout << "Roll No: " << get_roll() << endl;
    cout << "Marks 1: " << get_m1() << endl;
    cout << "Marks 2: " << get_m2() << endl;
    cout << "Marks 3: " << get_m3() << endl;
    grade();
}
int main()
{
    Student s1;
    s1.set_name("Yazdaan Ali");
    s1.set_roll(30);
    s1.set_marks(90, 93, 95);
    s1.display();
    return 0;
}
