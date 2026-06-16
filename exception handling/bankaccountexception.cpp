#include <iostream>
using namespace std;
class BankAccount
{
    int balance;

public:
    BankAccount()
    {
        balance = 1000;
        cout << "CURRENT BALANCE:" << balance << endl;
    }
    void withdraw(int amount)
    {
        try
        {
            if (amount > balance)
            {
                throw("INSUFFICIENT BALANCE EXCEPTION");
            }
            else
            {
                balance = balance - amount;
                cout << "WITHDRAWAL SUCCUSSEFUL! NEW BALANCE:" << balance << endl;
            }
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
 
};
int main()
{
    BankAccount b1;
    int withdrawal;
    cout << "ENTER WITHDRAWAL AMOUNT:";
    cin >> withdrawal;
    b1.withdraw(withdrawal);

    return 0;
}