#include <iostream>
using namespace std;
int main()
{
    int array[3];
    int index;
float  numerator;
float denominator;
    try
    {
        cout << "ENTER INDEX:";
        cin >> index;
        if (index > 3)
        {
            throw("ARRAY OUTOF BOUNDS");
        }
        cout << "ENTER NUMERATOR:";
        cin >> numerator;
        cout << "ENTER DENOMINATOR:";
        cin >> denominator;
        if (denominator == 0)
        {
            throw(0);
        }
        array[index]=numerator/denominator;
        cout<<"THE VALUE AT INDEX["<<index<<"]:"<<array[index]<<endl;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    catch (int num)
    {
        cout << "ERROR:DIVIDE BY" << num << "NOT POSSIBLE" << endl;
    }

return 0;
}