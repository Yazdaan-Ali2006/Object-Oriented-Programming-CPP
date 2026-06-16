#include <iostream>
using namespace std;
/*2. Design a BankAccount class with methods like deposit, withdraw, and
getBalance. Ensure you have a constructor to set an initial balance.*/
class BankAccount
{
    int current_balance;
    public:
    BankAccount()
    {
    }
    BankAccount(int a)
    {
        current_balance = a;
    }

    int get_balance()
    {
        return current_balance;
    }
    void withdraw(int amount)
    {
        current_balance -= amount;
    }
    void deposit_amount(int amount)
    {
        current_balance += amount;
    }
};
void menu()
{
    cout << "========WELCOME TO BANK========" << endl;
    cout << "1-WITHDRAW" << endl;
    cout << "2-DEPOSIT" << endl;
    cout << "3-CHECK BALANCE" << endl;
    cout << "4-EXIT" << endl;
}

int main()
{
    int bal = 100;
    BankAccount b1(bal);
    while (1)
    {
        int choice;
        int a;
        int b;
        menu();
        cout << "Enter Your Choice: " ;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Amount To Withdraw : ";
            cin >> a;
            if (a <= b1.get_balance())
            {
                b1.withdraw(a);
                cout << "Withdraw Successful!" << endl;
            }
            else
            {
                cout << "Invalid Amount!!" << endl;
            }
            break;

        case 2:
            cout << "Enter Amount To Deposit: ";
            cin >> b;
            b1.deposit_amount(b);
            cout << "Deposit Successful!" <<endl;
            break;

        case 3:
            cout << "Current Balance: " << b1.get_balance()<<endl;
            break;

        case 4:
            cout << "Exiting!!!" << endl;
            return 0;
        }
    }

    return 0;
}