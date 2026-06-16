#include <iostream>
using namespace std;
/*How would you access the contents of data of each element of myclass array? Add code in
the above program to do the following:
a. Assign values to array data of each element of myclass array.
b. Display contents of data of each element of myclass array*/

class myclass
{
    int data[2];  
public:
    int* p;       
    myclass()
    {
        p = data; 
    }
};

int main()
{
    myclass* cp;
    cp = new myclass[3]; 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter data[" << j << "] for object " << i + 1 << ": ";
            cin >> cp[i].p[j];
        }
    }

    cout <<"Displaying contents of data arrays:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Object " << i + 1 << ": ";
        for (int j = 0; j < 2; j++)
        {
            cout << cp[i].p[j] << " "; 
        }
        cout << endl;
    }

    delete[] cp; 
    
    return 0;
}
