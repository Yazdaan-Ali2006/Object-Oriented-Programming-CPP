#include <iostream>
using namespace std;
class base
{ 
    int *arr[3];
    string name;

public:
    
    base()
    {
        name = "none";
        for (int i = 0; i < 3; i++)
        {
            arr[i] = 0;
        }
    }
    base(string n, int *array[])
    {
        name = n;
        for (int i = 0; i < 3; i++)
        {
            arr[i] = array[i];
        }
    }
        void setarr(int i,int val){
       *arr[i]=val;
    }
    base(const base &b)
    {  name=b.name;
        for(int i=0;i<3;i++){
            arr[i]=new int(*b.arr[i]) ;
        }

    }
    void display(){
        for(int i=0;i<3;i++){
            cout<<*arr[i]<<endl;
        }
    }
~base(){
    cout<<"Destructor called......"<<endl;
}
};
int main()
{   
    int a=1;
    int b=2;
    int c=3;
    int *arr[3]={&a,&b,&c};
    base b1("Yazdaan",arr);
  
   // base b2(b1);
    
   base b2= b1;
    b1.display();
    b2.setarr(1,7777);
    b1.display();
    
    return 0;
}