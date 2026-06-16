#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr; // fixed size stack (size = 5)
    int top;

public:
    Stack()
    {
        top = -1; // stack is empty
        arr = new int[5];
    }

    void push(int x)
    {
        if (top == 4)
        {
            throw overflow_error("Stack Overflow!");
        }
        /*
        top++
        arr[top]  this is wrong
        top++
        */
        arr[++top] = x;
        //cout<<"PUSHED ELEMENT:"<<x<<endl;
    }

    void pop()
    {
        if (top == -1)
        {
            throw underflow_error("Stack Underflow!");
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display()
    {
        if (top == -1)
        {

            throw underflow_error("EXCEPTION:Stack is empty\n");
        }
        cout<<"BOTTOM TO TOP"<<endl;
        for (int i = 0; i <=top; i++)
        {   
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50); 
        //10
        //20
        //30
        //40
        //50 last
        s.push(60);
    }
    catch (const overflow_error &e1)
    {
        cout << e1.what() << endl;
    }

    try
    {

        s.display();

        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();

        s.pop(); // This will cause Underflow
    }
    catch (const underflow_error &e1)
    {
        cout << e1.what() << endl;
    }

    catch (...)
    {
        cout << "DEFAULT:CATCH" << endl;
    }

    return 0;
}