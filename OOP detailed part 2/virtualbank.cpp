/*Base class Account

Attributes: accountNumber (int), balance (float)

Methods:

virtual void input() → input accountNumber and balance

virtual void display() → display accountNumber and balance

Virtual destructor with message "DESTRUCTOR OF ACCOUNT"

Derived class Savings

Additional attribute: interestRate (float)

Override input() → input interestRate

Override display() → show accountNumber, balance, interestRate

Destructor with message "DESTRUCTOR OF SAVINGS"

Derived class Current

Additional attribute: overdraftLimit (float)

Override input() → input overdraftLimit

Override display() → show accountNumber, balance, overdraftLimit

Destructor with message "DESTRUCTOR OF CURRENT"

In main()

Create an array of base-class pointers: Account* accounts[2];

Assign new Savings() and new Current() to array

Call input() and display() through base pointer

Delete objects (check virtual destructor works)*/
#include<iostream>
using namespace std;
class accountnumber{
    protected:
    int num;
    float balance;
    public:
    accountnumber(){
        num=0;
        balance=0;
    }
    virtual void input(){
        cout<<"Enter account number:"<<endl;
        cin>>num;
        cout<<"Enter balance:"<<endl;
        cin>>balance;
        
    }
    virtual void display(){
        cout<<"Account Num:"<<num<<endl;
        cout<<"Balance:"<<balance<<endl;
    }
    virtual ~accountnumber(){
        cout<<"ACC DESTRUCTOR"<<endl;
    }
    };
    class saving:public accountnumber{
        protected:
        float interestrate;
        public:
        saving(){
            interestrate=0;
        }
        void display()override{
            cout<<"HI SAVING:"<<endl;
        }

        ~saving(){
            cout<<"SAVING DEST" <<endl;
        }

    };

int main()
{  accountnumber *ptr=new saving();
   ptr->display();
    return 0;
}