#include<iostream>
#include<fstream>
using namespace std;

int main()

{
    string st1 = "HELLO WORLD";
    string st2;

    // WRITE first
    ofstream out("samplefile.txt");
    out << st1;
    out.close();
    // READ after writing
    ifstream in("samplefile.txt");
    getline(in, st2);
    cout << st2;
    return 0;
}
    
    


