#include <iostream>
using namespace std;
int main()
{
    try
    {
        int *ptr = new int[1000000000];
        cout << "memory allocaion successful" << endl;
        delete[] ptr;
    }
    catch(){
        
    }
    return 0;
}