#include <iostream>
using namespace std;
class array
{
    int size;
    int *p;

public:
    array(int s)
    {
        size = s;
        p = new int[size];
    }
    array(const array &c)
    {
        size = c.size;
        p = new int[size];
        for (int i = 0; i < size; i++)
        {
            p[i] = c.p[i];
        }
    }
    void set()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "INTEGER" << i + 1 << " : ";
            cin >> p[i];
        }
    }
    int add()
    {
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            total += p[i];
        }
        return total;
    }
    ~array()
    {
        cout << "array destroyed" << endl;
        delete[] p;
    }
    display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "VALUE " << i + 1 << " = " << p[i] << endl;
            ;
        }
    }
};

int main()

{
    int size;
    cout << "Enter the size of array:" << endl;
    cin >> size;
    array a1(size);
    a1.set();
    a1.display();
    cout<<"Copying the array "<<endl;
        array a2(a1);
    a2.display();

    return 0;
}