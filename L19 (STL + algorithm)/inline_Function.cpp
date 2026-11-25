#include<iostream>
using namespace std;

inline int maxi(int& a, int& b){    // reduces function call stacking
                                    // inc readability

    
    // int& make alias of a and b and do not use extra space.
    // inline increase  performance ; no function call overhead.

    // 1 line -> compiler make finction inline
    // 2-3 lines -> compiler ki marji
    // >3 lines -> compiler says bhag ja but work toan krega.


    // when inline function is of 1 line.
    // inline function remove maxi(a, b) in line 19 ,
    // and in that place it puts return statement if possible

    

    return a>b?a:b;                    /*ternary operator.*/
}

int main(){
    int a, b, c;
    cin>>a>>b;

    // inline function 
    c = maxi(a,b);
    cout<<c;
    return 0;

}