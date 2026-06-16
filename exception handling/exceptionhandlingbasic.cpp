#include <iostream>
using namespace std;
int main()
{
    int a; // numerator
    int b; // denominator

    try
    {
        cout << "ENTER NUMERATOR: ";
        cin >> a;
        cout << "ENTER DENOMINATOR: ";
        cin >> b;

        if (a == 0 && b == 0)
        {
            throw(0);
        }
        else if(b == 0)
        {
            throw("UNDEFINED");
        }
        else
        {
            cout << a << "/" << b << endl;
        }
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    catch (int n)
    {
        cout << n << endl;
    }
    catch(...){
        cout<<"unkonwo exception"<<endl;
    }
    return 0;
}