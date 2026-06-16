#include <iostream>
using namespace std;
class complex_number
{
private:
    int real;
    int img;
public:
    void set_real(int r) //setter inline function
    {
        real = r;
    }
    void set_img(int i)//setter inline function
    {
        img = i;
    }
    int get_real() //getter inline function
    {
        return real;
    }
    int get_img()   //getter inline functioninline function
    {
        return img;
    }
    void display();
};
void complex_number::display() //out_of_line function
{
    cout << get_real() << "+" << get_img() << "j" << endl;
}
int main()
{    complex_number c1;
     int r, i;
    cout << "ENTER A REAL NUMBER: ";
    cin >> r;
    cout << "ENTER A IMAGINARY NUMBER: ";
    cin >> i;
    c1.set_real(r);
    c1.set_img(i);
    c1.display();
    return 0;}
