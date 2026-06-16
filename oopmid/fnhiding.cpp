#include <iostream>
using namespace std;
class Parent
{
public:
    void display(int x) { std::cout << "Int: " << x << std::endl; }
};

class Child : public Parent
{
public:
    Parent::display(); // This "unhides" the Parent's display(int)
    void display(std::string s) { std::cout << "String: " << s << std::endl; }
};

int main()
{
    Child obj;
    obj.display(10);      // Now this WORKS!
    obj.display("Hello"); // This also WORKS!
}