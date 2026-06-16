#include <iostream>
using namespace std;

class complex_number
{
public:
    int real;
    int img;

    void set_real(int r)
    {
        real = r;
    }
    void set_img(int i)
    {
        img = i;
    }
    int get_real()
    {
        return real;
    }
    int get_img()
    {
        return img;
    }
    void display();

};
void complex_number::display() 
{
    cout << get_real() << "+" << get_img() << "j" << endl;
}

int main()
{
    complex_number c1;
    c1.set_real(4);
    c1.set_img(3);
    c1.display();
    return 0;
}