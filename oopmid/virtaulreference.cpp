#include <iostream>
using namespace std;
class A
{
public:
    virtual void display()
    {
        cout << " CLASS A" << endl;
    }
};
class B : public A
{
public:
    void display() override
    {
        cout << "CLASS B" << endl;
    }
};
int main()
{
    B b1;
    A a1;
    A &ra = a1; // PARENT CLASS KE PASS APNA KA REF
    A &rb = b1; //PARENT CLASS KE PASS CHILD A REF
    ra.display();
    rb.display();

    rb.A::display();
    ra.A::display();

    //LESSON: hamesha jb bhi hamary pass base ka ref hoga to hm usay ya to child ya parent ka display
    //scope reolution ki madat se run krwaskty hain LEKIN scope resolution se phly name BASE ka he aige
    //other wise error
    //SCOPE RESOLUTIION FORCED FULLY RUN KRWAIGA
    B obj;
    B &ref=obj;
    ref.display();
    ref.B::display();
    ref.A::display();
   //agr child ka ref ho to yaha hum dono EITHER BASE YA PHIR CHILD KO SCOPE RES se phy likhskty hain

    return 0;
}