#include <iostream>
#include <cstring>

using namespace std;
class student
{
    char *name;
    float mark[3];
    int rollno;

public:
    student()
    {
        name = new char[1];
        name[0] = '\0';

        rollno=0;
        mark[0]=mark[1]=mark[2] = 0;
    }
    student(float m[], int roll, char *n)
    {  
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        rollno = roll;
        for (int i = 0; i < 3; i++)
        {
            mark[i] = m[i];
        }
    }
    student(student &s)
    {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        rollno = s.rollno;
        for (int i = 0; i < 3; i++)
        {
            mark[i] = s.mark[i];
        }
        cout << "COPY CONSTRUCTOR IS WORKING" << endl;
    }
    ~student()
    {
        delete[] name;
        cout << "DESTURCTOR IS WORKING" << endl;
    }
    void setname(char *n)
    {    delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void setrollno(int roll)
    {
        rollno = roll;
    }
    void setmarks(float m[])
    {
        for (int i = 0; i < 3; i++)
        {
            mark[i] = m[i];
        }
    }
    float getmark1()
    {
        return mark[0];
    }

    float getmark2()
    {
        return mark[1];
    }

    float getmark3()
    {
        return mark[2];
    }

    void display()
    {
        cout << "NAME:" << name << endl;
        cout << "ROLL NO: " << rollno << endl;
        cout << "MARK 1: " << getmark1() << endl;
        cout << "MARK 2: " << getmark2() << endl;
        cout << "MARK 3: " << getmark3() << endl;

        float avg = ((getmark1() + getmark2() + getmark3()) / 3);
        if (avg >= 80)
        {
            cout << "GRADE : A" << endl;
        }
        else if (avg < 80 && avg >= 70)
        {
            cout << "GRADE : B" << endl;
        }
        else if (avg < 70 && avg >= 60)
        {
            cout << "GRADE : C" << endl;
        }
        else
        {
            cout << "FAIL!!" << endl;
        }
    }
};

int main()
{
    char temp[50];
    cout << "ENTER YOUR NAME: " << endl;
    cin >> temp;
    
    int roll;
    char *n=new char[strlen(temp)+1];
    strcpy(n,temp);
    float m[3];
    cout << "ENTER YOUR ROLL NO: " << endl;
    cin >> roll;
    for (int i = 0; i < 3; i++)
    {
        cout << "ENTER MARKS" << i + 1 << ":" << endl;
        cin >> m[i];
    }
    student s1(m,roll,n);
    s1.display();
 
    delete[]n;

    return 0;
}