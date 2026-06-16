#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    int studentage;
    cout << "ENTER STUDENT AGE:";
    try
    {
        cin >> studentage;
        if (studentage <= 0)
        {
            throw logic_error("Invalid Age");
        }
    }
    catch (const logic_error &l)
    {
        cout << "ERROR:" << l.what() << endl;
    }
    return 0;
}