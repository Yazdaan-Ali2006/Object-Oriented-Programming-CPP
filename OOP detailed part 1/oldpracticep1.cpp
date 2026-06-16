#include <iostream>
using namespace std;
class apartment
{
    string ownername;
    int apartmentnumber;
    float average;
    int monthlyrent[6];
    apartment()
    {
        ownername = "NONE";
        apartmentnumber = 000;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = 0;
        }
    }
    apartment(string o, int a, int arr[])
    {
        set_average();
        ownername = o;
        apartmentnumber = a;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = arr[i];
        }
    }
    apartment(apartment &c1)
    {
        ownername = c1.ownername;
        apartmentnumber = c1.apartmentnumber;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = c1.monthlyrent[i];
        }
        average = c1.average();
    }
    void set_monthlyrent(int arr[])
    {
        for (int i = 0; i < (5 + 1); i++)
        {

            monthlyrent[i] = arr[i];
        }

        void set_average()
        {
            float average;
            float sum;
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
        void set_rent(int arr[])
        {
            for (i = 0; i < 6; i++)
            {
                monthlyrent[i] = arr[i];
            }
        }
        void check()
        {
            int a = getavg();
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
            return apartment number;
        }
        void display()
        {
            cout << "OWNER'S NAME:" << get_name << endl;
            cout << "APARTMENT'S NUMBER:" << get_ap << endl;
            cout << "MONTHLY RENT------------" << endl;
            for (int i = 0; i < 6; i++)
            {
                cout << "MONTH(" << i + 1 << ")" : endl;
            }
            check();
        }
        void set_apartnum(int a)
        {
            apartmentnumber = a;
        }
    };
    int main()
    {   int rent[6];
        string ownername;
        int apartnum;
        cout << "ENTER OWNER'S NAME:";
        cin >> ownername;
        cout << "ENTER APARTMENT NUMBER";
        cin >> apartnum;
        int *a = new apartment[6];
        cout << "ENTER MONTHLY RENT" : endl;
        int i
        for ( i = 0; i < 6; i++)
        {
            cout << "ENTER FOR MONTH(" << i + 1 << "):";
            cin >> rent[i];}
            a[i].setname(name);
            a[i].set_apartnum(apartnumber);
            a[i].set_monthlyrent(rent);
            a[i].set_average();
        
    }