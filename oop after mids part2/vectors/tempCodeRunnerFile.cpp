#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
     int num[10];
     cout<<"descending order sorting";
     cout<<"\n=========================";
     cout<<"\n enter 10 values = "<<endl;
     cout<<"\n\t\t\t\t";
     for(int i=0;i<=9;i++){
          cin>>num[i];
     }
     sort(num,num+10);
     cout<<"\n so the numbers in descending order are :\n";
     for(int i=0;i<=9;i++){
          cout<<"\n\t\t\t\t"<<num[i];
          }
return 0;
}