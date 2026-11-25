#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int *p = 0;
    p = &a;
    cout<<p <<" "<<*p;

}