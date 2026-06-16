#include <iostream>
using namespace std;
class student
{
    string name;
    int roll;
    float gpa;
    int semester;

public:
    student(string n = "null", int r = 0, float g = 0, int sem = 0)
    {
        name = n;
        roll = r;
        gpa = g;
        semester = sem;
    }
    void setsem(int sem)
    {
        semester = sem;
    }
    void setname(string n)
    {
        name = n;
    }
    void setroll(int r)
    {
        roll = r;
    }
    void setgpa(float g)
    {
        gpa = g;
    }
    string getname()
    {
        return name;
    }
    int getsem()
    {
        return semester;
    }
    int getroll()
    {
        return roll;
    }
    float getgpa()
    {
        return gpa;
    }
    void display()
    {
        cout << "| NAME:" << name << "|" << "| ROLL NO:" << roll << "|" << "| SEMESTER:" << semester << "|" << "| GPA:" << gpa << "|" << endl;
    }
};

int main()
{
    string n;
    int r;
    int sem;
    float g;
    student s[1];
    int i;
    for (i = 0; i < 1; i++)
    {
        cout << "ENTER THE INFO OF STUDENT " << i + 1 << endl;
        cout << "ENTER ROLLNO=";
        cin >> r;
        cout << "ENTER NAME=";
        cin >> n;
        cout << "ENTER SEMESTER=";
        cin >> sem;
        cout << "ENTER GPA=";
        cin >> g;
        cout << "----------------------" << endl;
        s[i].setname(n);
        s[i].setroll(r);
        s[i].setgpa(g);
        s[i].setsem(sem);
    }

    cout << "STUDENT INFORMATION" << endl
         << "-------------------" << endl;
    for (i = 0; i < 1; i++)
    {
        s[i].display();
    }

    
    /*THE FOLLOWING CODE IS AFTER THE PREVIOUS CODE*/

    student *ptr = &s[0];
    int search;
    int j;
    int found = 0;
    cout << "Enter roll no which you want to found" << endl;
    cin >> search;
    for (j = 0; j < 10; j++)
    {
        if ((ptr + j)->getroll() == search)
        {  
            found++;
            break;
        }
    }
    if (found == 0)
    {
        cout << "Record not found!" << endl;
    }
    else
    {
        cout << "Record found" << endl;
        s[j].display();
    }

    return 0;
}