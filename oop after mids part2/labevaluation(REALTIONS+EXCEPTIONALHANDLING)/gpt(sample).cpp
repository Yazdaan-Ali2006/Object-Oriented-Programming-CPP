#include <iostream>
using namespace std;
class course
{
private:
    string coursename;
    int credithours;

public:
    course()
    {
        coursename = "N/A";
        credithours = 0;
    }
    // parameterized constructor that throws an exception if the
    // course name is empty or the credit hours are less than or equal to zero.
    // It should also have a function to display course details.
    course(string cn, int cr)
    {

        if (cn == "")
        {
            throw("INVALID COURSE NAME");
        }
        coursename = cn;

        if (cr <= 0)
        {
            throw("INVALID CREDIT HOUR");
        }
        credithours = cr;
    }
    string getcoursename()
    {
        return coursename;
    }
    int getcredithours()
    {
        return credithours;
    }
    void displaycourse()
    {
        cout << "COURSE NAME:" << coursename << endl;
        cout << "CREDIT HOURS:" << credithours << endl;
    }
};
class professor
{
private:
    string name;

public:
    professor()
    {
        name = "N/A";
    }
    professor(string n)
    {
        try
        {
            if (n == "")
            {
                throw("INVALID COURSE NAME");
            }
            name = n;
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
    string getprofname()
    {
        return name;
    }
    void dipslayprof()
    {
        cout << "PROFESSOR:" << getprofname() << endl;
    }
};
class department
{
    course c[2];
    int counter;
    professor *ptr;

public:
    department(professor *p)
    {
        counter = 0;
        ptr = p;
    }
    void addcourse()
    {
        string cn;
        int cr;

        if (counter != 2)
        {
            try
            {
                cout << "ENTER COURSE" << endl;
                cin >> cn;
                cout << "ENTER CREDIT HOURS:" << endl;
                cin >> cr;
                c[counter++] = course(cn, cr);
            }
            catch (char const *msg)
            {
                cout << msg << endl;
            }
        }
    }
    void display()
    {
        ptr->dipslayprof();
        cout << "COURSES" << endl;
        for (int i = 0; i < counter; i++)
        {
            c[i].displaycourse();
        }
    }
};
int main()
{
    professor p1("ali");
    department d1(&p1);
    d1.addcourse();
    d1.addcourse();

    return 0;
}