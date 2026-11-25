#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    int i = 0;
    while (n!=0)
    {
        // xxxx        bitwise &
        // 0001
        // =  x  , x = 0 or 1
        int bit = n & 1;
        cout<<i+1<<"th bit :"<<bit<<endl;
        ans = (bit*pow(10,i))+ans;
        cout<<i+1<<"th ans :"<<ans<<endl;
        n = n>>1;
        i++;
    }
    cout<<ans<<endl;
    
}