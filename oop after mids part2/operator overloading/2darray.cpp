#include <iostream>
using namespace std;
class matrix
{
    int arr[3][3];

public:
    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    void input()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "ENTER ELEMENT [" << i + 1 << "][" << j + 1 << "] ";
                cin >> arr[i][j];
            }
        }
    }
    friend matrix operator+(matrix obj1, matrix obj2);
    friend matrix operator-(matrix obj1, matrix obj2);
};
matrix operator+(matrix obj1, matrix obj2)
{
    matrix temp;
    for (int i = 0; i < 3; i++)
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                temp.arr[i][j] = obj1.arr[i][j] + obj2.arr[1][2];
            }
        }
    return temp;
}
matrix operator-(matrix obj1, matrix obj2)
{
    matrix temp;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            temp.arr[i][j] = obj1.arr[i][j] - obj2.arr[i][j];
        }
    }
    return temp;
}

int main()
{
    matrix m1;
    m1.input();
    m1.display();
    matrix m2;
    m2.input();
    m2.display();
    matrix m3;
    m3=m1-m2;
    m3.display();

    return 0;
}