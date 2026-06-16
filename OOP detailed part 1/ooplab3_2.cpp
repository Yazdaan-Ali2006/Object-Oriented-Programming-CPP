#include<iostream>
using namespace std;
class balance{
    double cur_bal;
    string name;
 public:
    void set_data(double b,string s){
        cur_bal=b;
        name=s;

    }
balance(){}
~balance(){
    cout<<name<<"account is deleted!!!"<<endl;
}
void get_bal(double &n,string &s) {
    n=cur_bal;
    s=name;

}
};
int main()
{ balance *p;
    double n;
    string s;
    p=new balance[2];
    p[0].set_data(100,"yazdaan");
    p[1].set_data(1330,"ali");
    for(int i=0;i<2;i++){
        p[i].get_bal(n,s);
        cout<<s<<" has  balance: "<<n<<endl;
    }
    return 0;
}