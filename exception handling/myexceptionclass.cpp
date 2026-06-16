#include <iostream>
using namespace std;
class MyException
{
public:
    string str;
    int num;
    MyException(int n, string s)
    {
        num = n;
        str = s;
    }
};
int main()
{
    int positivenumber;
    cout << "ENTER A POSTIVE NUMBER" << endl;
    try
    {
        cin >> positivenumber;
        if (positivenumber <= 0)
        {
            throw MyException(positivenumber, "INVALID NUMBER");
        }
    }
    catch (MyException &e)
    {
        cout << e.str << " " << e.num << endl;
    }

    return 0;
}