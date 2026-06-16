#include <iostream>
using namespace std;
class vector
{
private:
    int vec[2];

public:
    vector()
    {
        vec[0] = 0;
        vec[1] = 0;
    }
    int &operator[](int index)
    {
        return vec[index];
    }
    friend ostream &operator<<(ostream &o, vector &obj)
    {
        o << "(" << obj.vec[0] << "," << obj.vec[1] << ")" << endl;
        return o;
    }
    friend istream &operator>>(istream &i, vector &obj)
    {
        cout << "ENTER X-AXIS" << endl;
        i >> obj.vec[0];

        cout << "ENTER Y-AXIS" << endl;
        i >> obj.vec[1];
        return i;
    }
};
int main()
{
    vector v1;
    cin >> v1;
    v1[0]=1;
    v1[1]=1; 
    cout << v1;
    


    return 0;
}