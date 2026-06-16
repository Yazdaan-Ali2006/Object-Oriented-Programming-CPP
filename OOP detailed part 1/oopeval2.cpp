#include <iostream>
#include <string.h>
using namespace std;
/*Design a class named Apartment that has the following data members: owner name (string), apartment number (int),
 monthly rent (double array of size 6), and average rent (float).
Implement a default constructor, parameterized constructor,
and copy constructor for the class. Also provide suitable getter and setter functions for all data members.
Write a member function to calculate the average rent by adding all
six monthly rent values and dividing the sum by 6.
Using conditional statements, display “Economical”
 if the average rent is less than or equal to 30000, “Standard”
  if it is greater than 30000 and less than 60000, otherwise display “Premium”.*/
class apartment
{
    string ownername;
    int apartmentnumber;
    double monthlyrent[6];
    float averagerent;

public:
    apartment()
    { // default constructor
        ownername = "null";
        apartmentnumber = 0;
        averagerent = 0.0;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = 0;
        }
    }

    apartment(string name, int apnum, double rentval[])
    {
        ownername = name;
        apartmentnumber = apnum;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = rentval[i];
        }
        setaverage();
    }
    void setaverage()
    {
        averagerent = 0;
        for (int i = 0; i < 6; i++)
        {
            averagerent += monthlyrent[i];
        }
        (averagerent /= 6);
    }
    void setname(string a)
    {
        ownername = a;
    }
    void setapartmentnum(int a)
    {
        apartmentnumber = a;
    }
    void setrent(double rentval[])
    {
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = rentval[i];
        }
    }
    int getapartmentnum()
    {
        return apartmentnumber;
    }
    string getname()
    {
        return ownername;
    }
    float getaverage()
    {
        return averagerent;
    }
    void  check()
    {
        float a = getaverage();
        if (a <= 30000)
        {
            cout << "Economical" << endl;
        }
        else if (a > 30000 && a <= 60000)
        {
            cout << "Standard" << endl;
        }
        else
        {
            cout << "Premium" << endl;
        }
    }
    void display(){
        cout<<"Name: "<<getname()<<endl;
        cout<<"Apartment Number: "<<getapartmentnum()<<endl;
        cout<<"  MONTHLY RENT  "<<endl;
        for(int i=0;i<6;i++){
            cout<<"Month("<<i+1<<"):"<<i+1<<monthlyrent[i]<<endl;
        }
        cout<<"Average Rent "<<getaverage()<<endl;
        check();
    }
    apartment(apartment &a)
    {
        ownername = a.ownername;
        apartmentnumber = a.apartmentnumber;
        averagerent = a.averagerent;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = a.monthlyrent[i];
        }
    }
};
int main()
{   
    string name;
    int apartmentnumber;
    double rent[6];
    apartment *a = new apartment[3];
    float max;
     int i,j,index;
    for ( i = 0; i < 3; i++)
    {
         cout<<"ENTER NAME"<<i+1<<":"; cin>>name;
         cout<<"ENTER APARTMENT NO"<<i+1<<":"; cin>>apartmentnumber;
         for(int j=0;j<6;j++){
         cout<<"ENTER RENT OF MONTH NO "<<j+1<<":"; cin>>rent[j];
         }
         a[i].setname(name);
         a[i].setapartmentnum(apartmentnumber);
         a[i].setrent(rent);
         a[i].setaverage();
        }
        max=a[0].getaverage();
        for(int i=0;i<3;i++){
            cout<<"average of "<<i+1<<" = "<<a[i].getaverage()<<endl;
            a[i].check();
        }
            for(j=0;j<3;j++){

            if(max<a[j].getaverage()){
                max=a[j].getaverage();
            }    index=j;
        }
        cout<<j<<endl;
        cout<<"MAXIMUM AVERAGE IS:"<<max<<endl;
        a[index].display();
        delete [] a;
    return 0;
}