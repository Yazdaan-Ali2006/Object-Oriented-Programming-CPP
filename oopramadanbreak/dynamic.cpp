#include <iostream>
using namespace std;
int main()
{
    // static int array[3] = {1, 2, 3};
    int capacity;
    int *array=new int[capacity];
    cout << "number of elements you want to enter" << endl;
     for (int i = 0; i < 3; i++)
    {     cout<<"enter element num"<<i+1<<endl;
        cin>> array[i];

    }
       for (int i = 0; i < 3; i++)
    {     cout<<"Element:"<<array[i]<<endl;

    }
    return 0;
}