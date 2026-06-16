#include <iostream>
#include <vector>
using namespace std;
void displayvector(vector<int> &v) // DISPLAY
{
    cout << "PRINTING VECTOR DETAILS................." << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{

    vector<int> v1;
    int n;
    int a;
    cout << "ENTER THE SIZE OF VECTOR" << endl;
    cin >> n;
    //NORMAL INSERTION
    for (int i = 0; i < n; i++)
    {
        cout << "ENTER ELEMENT :" << endl;
        cin >> a;
        v1.push_back(a);
    }
    // INSERTION USING ITERATOR
    vector<int>::iterator itr = v1.begin();
    v1.insert(itr, 2, 200);
    displayvector(v1);

    // ANOTHER WAY
    vector<int> v2(4, 2);
    displayvector(v2);
    return 0;
}
