#include <iostream>
using namespace std;

class Course
{
public:
    string courseName;
    Course(string name) : courseName(name)
    {
        cout << "Course created: " << courseName << endl;
    }
};
class Student
{
public:
    string studentName;
    Student(string name) : studentName(name)
    {
        cout << "Student created: " << studentName << endl;
    }

    void enrollInCourse(Course *course)
    {
        cout << studentName << " enrolled in " << course->courseName << endl;
    }
};
int main()
{
    Course math("Mathematics");
    Course cs("Computer Science");
    Student john("John");
    john.enrollInCourse(&math);
    john.enrollInCourse(&cs);

    return 0;
}