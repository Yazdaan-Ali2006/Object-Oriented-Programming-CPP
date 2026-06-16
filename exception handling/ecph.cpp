#include <iostream>
#include <string>
using namespace std;

// 3 custom exception classes
class InvalidAgeException {
public:
    string msg;
    InvalidAgeException(string m) : msg(m) {}
};

class InvalidSalaryException {
public:
    string msg;
    InvalidSalaryException(string m) : msg(m) {}
};

class InvalidHeightException {
public:
    string msg;
    InvalidHeightException(string m) : msg(m) {}
};

class URS { // User Registration System
private:
    int age;
    int salary;
    int height;

public:
    URS() : age(20), salary(50000), height(500) {}

    void setAge(int a) {
        if (a <= 0 || a >= 120) 
            throw InvalidAgeException("Age must be > 0 and < 120");
        age = a;
    }
    void setSalary(int s) {
        if (s <= 0) 
            throw InvalidSalaryException("Salary must be > 0");
        salary = s;
    }
    void setHeight(int h) {
        if (h <= 0) 
            throw InvalidHeightException("Height must be > 0 cm");
        height = h;
    }
    
    void display() {
        cout << "Registered: Age=" << age << ", Height=" << height 
             << "cm, Salary=" << salary << endl;
    }
};

int main() {
    URS obj1;
    int age, height, salary;

    try {
        cout << "ENTER YOUR AGE" << endl;
        cin >> age;
        obj1.setAge(age);  // validates + throws if bad

        cout << "ENTER YOUR HEIGHT" << endl;
        cin >> height;
        obj1.setHeight(height);  // validates + throws if bad

        cout << "ENTER YOUR SALARY" << endl;
        cin >> salary;
        obj1.setSalary(salary);  // validates + throws if bad

        cout << "All data valid!" << endl;
        obj1.display();
    }
    catch (const InvalidAgeException &e) {
        cout << "Age Error: " << e.msg << endl;
    }
    catch (const InvalidHeightException &e) {
        cout << "Height Error: " << e.msg << endl;
    }
    catch (const InvalidSalaryException &e) {
        cout << "Salary Error: " << e.msg << endl;
    }

    return 0;
}