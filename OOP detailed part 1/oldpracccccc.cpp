#include <iostream>
#include <string>
using namespace std;

class apartment
{
    string ownername;
    int apartmentnumber;
    float average;
    int monthlyrent[6];

public:
    apartment()
    {
        ownername = "NONE";
        apartmentnumber = 0;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = 0;
        }
        average = 0;
    }

    apartment(string o, int a, int arr[])
    {
        ownername = o;
        apartmentnumber = a;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = arr[i];
        }
        set_average();
    }

    apartment(apartment &c1)
    {
        ownername = c1.ownername;
        apartmentnumber = c1.apartmentnumber;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = c1.monthlyrent[i];
        }
        average = c1.average;
    }

    void set_monthlyrent(int arr[])
    {
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = arr[i];
        }
    }

    void set_average()
    {
        float sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += monthlyrent[i];
        }
        average = sum / 6;
    }

    float get_avg()
    {
        return average;
    }

    void check()
    {
        float a = get_avg();
        if (a <= 30000)
        {
            cout << "ECONOMICAL" << endl;
        }
        else if (a > 30000 && a <= 50000)
        {
            cout << "MODERATE" << endl;
        }
        else
        {
            cout << "EXPENSIVE" << endl;
        }
    }

    string get_name()
    {
        return ownername;
    }

    int get_ap()
    {
        return apartmentnumber;
    }

    void display()
    {
        cout << "OWNER'S NAME: " << get_name() << endl;
        cout << "APARTMENT'S NUMBER: " << get_ap() << endl;
        cout << "MONTHLY RENT------------" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "MONTH(" << i + 1 << "): " << monthlyrent[i] << endl;
        }
        check();
    }

    void set_apartnum(int a)
    {
        apartmentnumber = a;
    }

    void set_name(string n)
    {
        ownername = n;
    }
};

int main()
{
    int rent[6];
    string ownername;
    int apartnum;
    apartment *arr = new apartment[2];
    apartment a;
    int i, j;
    for (j = 0; j < 2; j++)
    {
        cout << "ENTER OWNER'S NAME: ";
        cin >> ownername;

        cout << "ENTER APARTMENT NUMBER: ";
        cin >> apartnum;

        cout << "ENTER MONTHLY RENT" << endl;

        for (i = 0; i < 6; i++)
        {
            cout << "ENTER FOR MONTH(" << i + 1 << "): ";
            cin >> rent[i];
        }

        arr[j].set_name(ownername);
        arr[j].set_apartnum(apartnum);
        arr[j].set_monthlyrent(rent);
        arr[j].set_average();
    }

    for (j = 0; j < 2; j++)
    {
        arr[j].display();
    }
    int k = 0;
    float max = arr[0].get_avg();
    for (i = 0; i < 2; i++)
    {
        if (max < arr[i].get_avg())
        {
            max = arr[i].get_avg();
            k = i;
        }
    }
    cout<<"OWNER WITH MAXIMUM RENT"<<endl;
    arr[k].display();
    delete[] arr;
    return 0;
}