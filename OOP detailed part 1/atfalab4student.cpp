#include <iostream>
#include <string.h>
using namespace std;

class student
{
protected:
    char *name;
    int rollno;
    double marks[5];
    float percentage;

public:
    student() {}

    student(char *s, int r, double m[])
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        rollno = r;

        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
    }

    virtual void percent()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        percentage = (sum / 500) * 100;
    }

    virtual void display()
    {
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollno;
        cout << "\nPercentage: " << percentage << "%\n";
    }

    virtual ~student()
    {
        delete[] name;
    }
};

class scienceStudent : public student
{
    double practical;   // 150 marks

public:
    scienceStudent(char *s, int r, double m[], double p)
        : student(s, r, m)
    {
        practical = p;
        percent();
    }

    void percent()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        sum += practical;
        percentage = (sum / 650) * 100;
    }

    void display()
    {
        cout << "\n--- Science Student ---";
        student::display();
        cout << "Practical Marks: " << practical << endl;
    }
};

class artsStudent : public student
{
    double optional;   // 100 marks

public:
    artsStudent(char *s, int r, double m[], double o)
        : student(s, r, m)
    {
        optional = o;
        percent();
    }

    void percent()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        sum += optional;
        percentage = (sum / 600) * 100;
    }

    void display()
    {
        cout << "\n--- Arts Student ---";
        student::display();
        cout << "Optional Subject Marks: " << optional << endl;
    }
};


int main()
{
    double m1[5] = {80, 75, 90, 85, 70};
    double m2[5] = {60, 90, 86, 55, 75};

    scienceStudent s1("ALEX", 342, m1, 140);
    artsStudent a1("SMITH", 212, m2, 85);

    s1.display();
    a1.display();

    return 0;
}
