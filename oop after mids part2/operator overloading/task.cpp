#include <iostream>
using namespace std;

class BankAccount {
protected:
    float balance;

public:
      BankAccount() {
        balance = 5000;
    }

    virtual float calculate_interest() = 0;


    void operator+=(float amount) {
        if (amount > 0)
            balance += amount;
    }

    
    void operator-=(float amount) {
        if (amount > 0 && balance > amount)
            balance -= amount;
        else
            cout << "insufficient balance!"<<endl;
    }

    bool operator>(float value) {
        return balance > value;
    }

    bool operator<(float value) {
        return balance < value;
    }

    bool operator==(float value) {
        return balance == value;
    }

    bool operator!=(float value) {
        return balance != value;
    }

    
    float getBalance() {
        return balance;
    }
};

class SavingAccount : public BankAccount {
private:
    float interestrate;

public:
    
    SavingAccount(float rate) {
        interestrate = rate;
    }

    float calculate_interest() override {
        return balance * interestrate / 100;
    }
};


int main() {
    SavingAccount ac(5); 


    ac += 1000;  
    ac -= 200; 

    cout << "Balance: " << ac.getBalance() << endl;
    cout << "Interest: " << ac.calculate_interest() << endl;

    
}