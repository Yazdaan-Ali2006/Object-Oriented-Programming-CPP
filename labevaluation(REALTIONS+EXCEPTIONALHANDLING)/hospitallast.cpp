#include <iostream>
#include <stdexcept>
using namespace std;
class patient
{
    string name;
    int age;
    int bill;

public:
    patient()
    {
        age = 1;
        name = "N/A";
        bill = 1;
    }
    patient(string n, int a, int b)
    {
        if (n == "")
        {
            throw invalid_argument("ERROR STRING CANT BE EMPTY");
        }
        name = n;
        if (a <= 0)
        {
            throw invalid_argument("ERROR AGE CAN NEVER BE NEGATIVE");
        }
        age = a;
        if (b <= 0)
        {
            throw invalid_argument("ERROR PRICING CAN NEVER BE 0 OR NEGATIVE");
        }
        bill = b;
    }
    string getname()
    {
        return name;
    }
    int getbill()
    {
        return bill;
    }
    int getage()
    {
        return age;
    }
    void display()
    {
        cout << "NAME:" << getname() << endl;
        cout << "BILL:" << getbill() << endl;
        cout << "AGE:" << getage() << endl;
    }
};
class doctor
{
    string name;
    string specilization;

public:
    doctor()
    {
        name = "N/A";
        specilization = "N/A";
    }
    doctor(string n, string s)
    {
        if ((n == "") || (s == ""))
        {
            throw invalid_argument("ERROR STRING CAN NEVER BE EMPTY");
        }
        name=n;
        specilization=s;
    }
    string getname()
    {
        return name;
    }
    string getspecilization()
    {
        return specilization;
    }
    void displaydoc()
    {
        cout << "DOCTOR:" << getname() << endl;
        cout << "SPECIALIZATION:" << getspecilization() << endl;
    }
};
class hospital
{
    patient p[3];
    int counter;
    doctor *d;

public:
    hospital(doctor *dptr)
    {
        d = dptr;
        counter = 0;
    }
    void addpatient()
    {
        if (counter < 3)
        {
            try
            {
                string n;
                int a, b;
                cout << "ENTER NAME:";
                cin >> n;
                cout << "ENTE AGE:";
                cin >> a;
                cout << "ENTER BILL:";
                cin >> b;
                p[counter++] = patient(n, a, b);
            }
            catch (invalid_argument &e1)
            {
                cout << e1.what() << endl;
            }
        }
        else
        {
            cout << "ARRAY IS FULL" << endl;
        }
    }
    void removepatient()
    {
        string n;
        cout << "ENTER NAME:";
        cin >> n;
        for (int i = 0; i < counter; i++)
        {
            if (p[i].getname() == n)
            {
                for (int j = i; j < counter - 1; j++)
                {
                    p[j] = p[j + 1];
                }
                --counter;
            }
        }
    }
    void display()
    {
        d->displaydoc();
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
    h1.addpatient();
    h1.addpatient();
    h1.addpatient();
    h1.display();

    return 0;
}