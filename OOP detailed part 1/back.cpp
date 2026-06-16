#include <iostream>
using namespace std;
class bank
{
    int amount;
    static int count;

public:
    bank(int a = 0)
    {
        amount = a;
        count++;
    }
    void setamount(int a)
    {
        amount = a;
    }
    int getamount()
    {
        return amount;
    }
    void withdraw(int a)
    {
        amount -= a;
    }
    void deposit(int a)
    {
        amount += a;
    }
    void display()
    {
          cout << "CURRENT BALANCE: " << amount << endl;
        cout<<"CURRENT COUNT: "<<getcount()<<endl;
    }
static int getcount(){
    return count;
}
    ~bank()
    {
        cout << "BANK IS CLOSED!" << endl;
        count--;
    }
};
int bank::count = 0;
int main()
{int a,b,c;
cout<<"ENTER AMOUNT:"<<endl;
cin>>a;

 bank b1(a);
 cout<<"ENTER AMOUNT TO DEPOSIT"<<endl;
 cin>> b;
 b1.deposit(b);

 cout<<"ENTER AMOUNT TO WITHDRAW"<<endl;
cin>>c;
if(b1.getamount()<c){
    cout<<"INVALID AMOUNT"<<endl;
}
else{
b1.withdraw(c);
b1.display();
}

    return 0;
}