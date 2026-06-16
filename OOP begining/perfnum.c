#include <stdio.h>
#include <stdbool.h>
bool checkPerfectNumber(int num) {    
    int i;
    int count=0;
    for(i=1;i<=num/2;i++){
        if(num%i==0){
            count+=i;
        }
    }

    if((count-2*num)==0){
        return true;
    }
    else{
      return false;
    }
    
    
}

int main() {

    return 0;
}