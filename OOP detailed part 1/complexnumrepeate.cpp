#include<iostream>
using namespace std;
class complexnum{
private:
int real;
int imaginary;
public:
complexnum(int r=0,int img=0):real(r),imaginary(img){
    cout<<"CONSTRUCTOR IS WORKING "<<endl;

}
void setreal(int r){
    real=r;}

    void setiamginary(int i){
        imaginary=i;
    }
    int getreal()const{
        return real;
    }
    int getimg()const{
        return imaginary;
    }
    void display(){
        cout<<real<<"+"<<imaginary<<"i"<<endl;
    }
    friend complexnum add(complexnum &a,complexnum &b);

}; complexnum add(complexnum &a,complexnum &b){
    complexnum temp;
    temp.real=a.getreal()+b.getreal();
    temp.imaginary=a.getimg()+b.getimg();
    return temp;
} 
int main()
{  
    complexnum c1(2,4);
    c1.display();
    complexnum c2(2,4);
    complexnum c3;
    c3=add(c1,c2);
    c3.display();
    return 0;
}