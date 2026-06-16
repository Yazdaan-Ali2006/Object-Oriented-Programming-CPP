#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string s1="HELLO WORLD";
    string s2;
    
    ofstream out("sampletext2.txt");
    out<<s1;
    out.close();

    ifstream in("sampletext2.txt");
    getline(in,s2);
    cout<<s2;



    return 0;
}