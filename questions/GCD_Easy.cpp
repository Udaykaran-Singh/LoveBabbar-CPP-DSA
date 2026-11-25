#include<iostream>
using namespace std;

int Gcd(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while (a!=b){
        if(a>b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}


int main(){
    int a,b;
    cout<<"enter value of a and b respectively :";
    cin>>a>>b;
    int gcd;

    // gcd = Gcd(a,b);
    // cout<<"gcd of a and b i.e. "<<a<<" and "<<b<<" is : "<<gcd<<endl<<endl;

    // // GCD with mod (Euclid's algorithm)
    // int x= max(a,b), y = min(a,b), z;
    // while(1){
    //     z = x%y;
    //     if (z == 0){
    //         cout<<"gcd of a and b i.e. "<<a<<" and "<<b<<" is : "<< y <<endl<<endl;
    //         break;
    //     }
    //     x = y;
    //     y = z;
    // }

    return 0;
}

//  LCM * GCD = a * b