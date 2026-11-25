#include<iostream>
using namespace std;
int fact(int a);
int nCr(int n, int r);
int main()
{
    int n , r;
    float val;
    cout<<"Enter value of n (in nCr) :";
    cin>>n;
    cout<<"Enter value of r (in nCr) :";
    cin>>r;
    val = nCr(n, r);
    cout<<n<<"C"<<r<<" = "<<val<<endl;
}

int nCr(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));
    // int num, den,ans;
    // num = fact(n);
    // cout<<"num = "<<num<<endl;
    // den = fact(r)*fact(n-r);
    // cout<<"den = "<<den<<endl;
    // ans = num/den;
    // return ans;
}

int fact(int a)
{
    if(a==0 || a==1){
        return 1;
    }
    else{
        return a*fact(a-1);
    }
}
