#include <iostream>
using namespace std;
/*
Create a class Car with the following:

Attributes:

string owner_name → name of the car owner

string model → car model

double monthly_expense[12] → expenses for each month

float avg_expense → average monthly expense

Methods:

Default constructor → initialize everything to default values.

Parameterized constructor → initialize attributes from arguments.

Copy constructor → copy one Car object to another.

Setters and getters for all attributes.

calculateAvgExpense() → calculate average of 12 months’ expenses.

displayExpenseCategory() → categorize the car:

"Low Expense" → avg_expense ≤ 5000

"Medium Expense" → 5000 < avg_expense < 15000

"High Expense" → avg_expense ≥ 15000

display() → show all details including average expense and category.

Main program tasks:

Allow the user to enter n car objects dynamically.

Display the expense category of each car.

Find and display the car with the highest average expense.*/
class car
{
    string name;
    string model;
    double monthlyexpense[12];
    float averageexpense;

public:
    car()
    {
        name = "null";
        model = "null";
        averageexpense = 0;
        for (int i = 0; i < 12; i++)
        {
            monthlyexpense[i] = 0;
        }
    }
    car(string n, string m, double e[])
    {
        name = n;
        model = m;
        for (int i = 0; i < 12; i++)
        {
            monthlyexpense[i] = e[i];
        }

        
    }
       car(car &c)
    {
        name = c.name;
        model = c.model;;
        for (int i = 0; i < 12; i++)
        {
            monthlyexpense[i] =c.monthlyexpense[i];
        }

        
    }
    void setexpense(double e[]){
           for (int i = 0; i < 12; i++)
        {
            monthlyexpense[i] = e[i];
        }

    }
    void setname(string n){
        name=n;
    }
    void setmodel(string n){
        model=n;
    }
    void setaverage(){
      averageexpense=0; 
        for(int i=0;i<12;i++){
          averageexpense+=monthlyexpense[i];
        }
         averageexpense/=12;  
    }
     
    void check(){
        float a=getavg();
        if(a<5000){
            cout<<"LOW COST"<<endl;
        }
        else if(a>=5000 && a<=10000){
            cout<<"NORMAL COST"<<endl;
        }
        else{
            cout<<"HIGH COST"<<endl;
        }
    }
    string getname()
{
    return name;
}
string getmodel(){
    return model;
}
float getavg(){
    return averageexpense;
}
void display()
{
    cout<<"NAME: "<<getname()<<endl;
    cout<<"MODEL: "<<getmodel()<<endl;
    cout<<"  FUEL EXPENSE  "<<endl;
    for(int i=0;i<12;i++){
        cout<<"MONTH("<<i+1<<")="<<monthlyexpense[i]<<endl;
    }
    cout<<"AVERAGE: "<<getavg()<<endl;
    check();
    
}

};
int main()
{  double expense[12];
   car *a=new car[2];
    int i,j;
    string name;
    string model;
    for(i=0;i<2;i++){
        cout<<"ENTER NAME: ";
        cin>>name;
        cout<<"ENTER MODEL:";
        cin>>model;
        for(j=0;j<12;j++){
            cout<<"ENTER FOR MONTH"<<(j+1)<<":";
            cin>>expense[j];
            
        }
        a[i].setname(name);
        a[i].setmodel(model);
        a[i].setexpense(expense);
        a[i].setaverage();
        
    }
        float max=0;
        int index=0;
        for(i=0;i<2;i++){
            if(max<a[i].getavg()){
                max=a[i].getavg();
                index=i;
            }
            cout<<"maximum average is:"<<max<<endl;
            a[index].display();


        }
        delete []a;
       
    return 0;
}