#include<iostream>
using namespace std;
/*Create a class Stack to represent stack of integers of fixed size. The member functions Push
and Pop must generate exception in case of overflow and underflow respectively. Write a driver
program that creates an object of stack and catches the exception.*/
class Stack{
    int stack[10];
    public:
    Stack(){
        for(int i=0;i<10;i++){
            stack[i]=0;
        }
    }
    void push(int element,int index){
        if(index<=9 && index>=0) {
            stack[index]=element;
        }
        else{
            throw("INVALID INDEX CANT PUSH");
        }

    }
      void pop(int element,int index){
        if(index<=9 && index>=0) {
            cout<<stack[index]<<endl;
        }
        else{
            throw("INVALID INDEX CANT POP");
        }

    }
};
int main()
{
    return 0;
}