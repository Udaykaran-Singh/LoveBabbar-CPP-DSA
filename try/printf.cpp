#include<iostream>
using namespace std;

int main(){
    int a, bin=0, digit, i = 0;
    cout << "enter a :";
    cin >> a;

    if (a>=0){
        while(a){
            digit = a&1;
            bin += digit*pow(10, i);
            i+=1;
            a = a>>1;
        }
    }
    else{
        a = -a;
        a = ~a;
        a += 1;
        while(a){
            digit = a&1;
            bin += digit*pow(10, i);
            i+=1;
            a = a>>1;
            
        }
        
    }
    cout<<bin;
    return 0;

}