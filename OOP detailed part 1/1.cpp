#include<iostream>
#include<voltagesense.h>
using namespace std;
int main()
{ const voltagesensor v1(2,23.1); 
    v1.display();
    return 0;
}