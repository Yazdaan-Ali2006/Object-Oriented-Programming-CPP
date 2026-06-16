
#include <iostream>
#include <stdexcept>
using namespace std;
class patient
{
private:
    string name;
    int age;
    int billamount;

public:
    patient()
    {
        name = "N/A";
        age = 1;
        billamount = 0;
    }
    patient(string n, int a, int b)
    {
        if (n == "")
        {
            throw invalid_argument("INVALID NAME");
        }
        name = n;
        if (a < 0)
        {
            throw invalid_argument("INVALID AGE");
        }
        age = a;
        if (b <= 0)
        {
            throw invalid_argument("INVALID BILL");
        }
        billamount = b;
    }
    string getname()
    {
        return name;
    }

    int getage()
    {
        return age;
    }
    int getbillamount()
    {
        return billamount;
    }
    void display()
    {
        cout << "NAME: " << getname() << endl;
        cout << "BILL AMOUNT: " << getbillamount() << endl;
        cout << "AGE: " << getage() << endl;
    }
};
class doctor
{
    string name;
    string speciliazation;

public:
    doctor()
    {
        name = "N/A";
        speciliazation = "N/A";
    }
    doctor(string n, string s)
    {
        if (n == "" || s == "")
        {
            throw invalid_argument("INVALID ENTRY OF DATA");
        }
        name = n;
        speciliazation = s;
    }

    string getdocname()
    {
        return name;
    }
    string getspeciliazation()
    {
        return speciliazation;
    }

    void doctordisplay()
    {
        cout << "DOCTOR:" << getdocname() << endl;
        cout << "SPECILIZATION:" << getspeciliazation() << endl;
    }
};
class hospital
{
    doctor *ptr;
    int counter;
    patient p[2];

public:
    hospital(doctor *dptr)
    {
        ptr = dptr;
        counter = 0;
    }
    void addPatient(string name, int age, int bill)
    {

        try
        {
            if (counter == 2)
            {
                throw runtime_error("LIMIT REACHED");
            }

            p[counter++] = patient(name, age, bill);
        }
        catch (runtime_error const &e1)
        {
            cout << e1.what() << endl;
        }
        catch (invalid_argument const &e1)
        {
            cout << e1.what() << endl;
        }
    }
    void removepatient(string name, int age, int bill)
    {
        for (int i = 0; i < counter; i++)
        {
            if (p[i].getname() == name && p[i].getage() == age && p[i].getbillamount() == bill)
            {
                for (int j = i; j < counter - 1; j++)
                {
                    p[j] = p[j + 1];
                }
                --counter;
            }
        }
    }
    void displayall()
    {
        ptr->doctordisplay();
        for (int i = 0; i < counter; i++)
        {
            p[i].display();
        }
    }
};
int main()
{
    doctor d1("ali", "ent");
    hospital h1(&d1);
    h1.addPatient("abc", 20, 20000);
    h1.removepatient("abc", 20, 20000);
    h1.addPatient("bcd", -1, 20000);
    h1.displayall();

    return 0;
}
