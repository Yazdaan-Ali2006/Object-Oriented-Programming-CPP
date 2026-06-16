#include <iostream>
using namespace std;
class printer
{
public:
    virtual void print()
    {
        cout << "PRINTING USING GENERIC PRINTER" << endl;
    }
    virtual ~printer()
    {
        cout << "GENERIC PRINTER DESTROYED" << endl;
    }
};
class inkjetprinter : public printer
{
public:
    void print() override
    {
        cout << "PRINTING USING INKJET PRINTER" << endl;
    }
    ~inkjetprinter() override
    {
        cout << "INKJET DESTORYED" << endl;
    }
};
class printer3d : public printer
{
public:
    void print() override
    {
        cout << "PRINTING USING 3D PRINTER" << endl;
    }

    ~printer3d()
    {
        cout << "DESTROYING 3D PRINTER" << endl;
    }
};
class laserprinter : public printer
{
public:
    void print() override
    {
        cout << "PRINTING USING LASER PRINTER" << endl;
    }
    ~laserprinter()
    {
        cout << "DESTROYING LASER PRINTER" << endl;
    }
};
void display(printer *p)
{
    p->print();
}
int main()
{
    printer *p[3];
    p[0] = new printer();
    p[1] = new inkjetprinter();
    p[2] = new laserprinter();
    p[3] = new printer3d();

    for (int i = 0; i < 4; i++)
    {
        p[i]->print();
    }
    for (int i = 0; i < 4; i++)
    {
        delete p[i];
    }

    return 0;
}