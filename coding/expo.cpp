#include<iostream>
using namespace std;

int power_logn(int a, int b){
    if(b == 0){
        return 1;
    }else if(b == 1){
        return a;
    }
    else if(b&1){                               // odd
        return a*power_logn(a*a, b>>1);
    }else{
        return power_logn(a*a , b>>1);          // b/2
    }
}

int main(){
    int a, b;
    cout<<"Enter a and b respectively to find a^b : ";
    cin>>a>>b;
    cout<<"Ans : "<<power_logn(a,b);
}