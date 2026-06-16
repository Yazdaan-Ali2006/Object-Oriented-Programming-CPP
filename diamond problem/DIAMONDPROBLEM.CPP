#include <iostream>
using namespace std;
class parent
{
public:
    string name;
      parent()
    {
        cout << "I AM THE PARENT CLASS" << endl;

        name ="none";
    }
    parent(string n)
    {
        cout << "I AM THE PARENT CLASS" << endl;

        name = n;
    }
    void printname()
    {

        cout<<name<<endl;
    }
};
class child1 : public virtual parent
{
public:
    child1(string n) : parent(n)
    {
        cout << "I AM THE FIRST CHILD" << endl;
    }
};
class child2 : public virtual parent
{
public:
    child2(string n) : parent(n)
    {
        cout << "I AM THE SECOND CHILD" << endl;
    }
};
class grandchild : public child1, child2
{
public:
    grandchild(string n1, string n2) : child1(n1), child2(n2)
    {
        cout << "I AM GRAND CHILD" << endl;
    }
};
int main() 
{
 grandchild g1("ali","abbas");
 g1.printname();

}