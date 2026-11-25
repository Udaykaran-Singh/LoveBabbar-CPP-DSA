#include<iostream>
using namespace std;
int main()
{
    // pow(a, b);
    int a,b,ans=1;
    cin>>a;
    cin>>b;
    for (int i = 1; i <= b; i++)
    {
        ans *= a;
    }
    cout<<ans; 
    

}