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
    virtual void calcproject() = 0;
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
        calcproject();
    }
    void calcproject() override
    {
        cout << "IJP" << endl;
    }
};
class printer3d : public printer
{
public:
    void print() override
    {
        cout << "PRINTING USING 3D PRINTER" << endl;
        calcproject();
    }
    void calcproject() override
    {
        cout << "3DP" << endl;
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
        calcproject();
    }
    ~laserprinter()
    {
        cout << "DESTROYING LASER PRINTER" << endl;
    }
    void calcproject() override
    {
        cout << "LSP" << endl;
    }
};

void menu()
{
    cout << "SELECT THE TYPE OF PRINTER" << endl;
    cout << "1)INKJET PRINTER" << endl;
    cout << "2)3D PRINTER" << endl;
    cout << "3)LASER PRINTER" << endl;
    cout << "ENTER YOUR CHOICE" << endl;
}
int main()
{
    int n;
    cout << "ENTER THE MUMBER OF PRINTERS" << endl;
    cin >> n;
    int choice;
    printer **p = new printer *[n];
    for (int i = 0; i < n; i++)
    {
        menu();

        cin >> choice;
        if (choice == 1)
        {
            p[i] = new inkjetprinter();
        }
        else if (choice == 2)
        {
            p[i] = new printer3d();
        }
        else if (choice == 3)
        {
            p[i] = new laserprinter();
        }

        else
        {
            cout << "INVALID" << endl;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        p[i]->print();
    }
    for (int i = 0; i < n; i++)
    {
        delete p[i];
    }
    delete[] p;
    return 0;
}