#include <iostream>
using namespace std;
class parent
{
public:

      parent()
    {
        cout << "I AM THE PARENT CLASS" << endl;

        
    }
   

};
class child1 : public virtual parent
{
public:
    child1()
    {
        cout << "I AM THE FIRST CHILD" << endl;
    }
};
class child2 : public virtual parent
{
public:
    child2()
    {
        cout << "I AM THE SECOND CHILD" << endl;
    }
};
class grandchild : public child1, child2
{
public:
    grandchild()
    {
        cout << "I AM GRAND CHILD" << endl;
    }
};
int main() 
{
 grandchild g1;


}