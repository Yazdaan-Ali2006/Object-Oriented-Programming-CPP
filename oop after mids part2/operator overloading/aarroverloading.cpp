#include <iostream>
using namespace std;
class MyArray
{
    int arr[5];

public:
    int &operator[](int index)
    {
        return arr[index];
    }
    friend ostream &operator<<(ostream &o, MyArray &obj)
    {
        for (int i = 0; i < 5; i++)
        {
            o << obj[i] << endl;
        }
        return o;
    }

    friend istream &operator>>(istream &in, MyArray &obj)
    {
        cout << "Enter 5 elements:\n";
        for (int i = 0; i < 5; i++)
        {
            in >> obj.arr[i];
        }
        return in;
    }
};
int main()
{
    MyArray obj1;
    cin >> obj1;
    cout << obj1;
    return 0;
}