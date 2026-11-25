#include<iostream>
using namespace std;
int fact(int a)
{
    if(a==0 || a==1){
        return 1;
    }
    else{
        return a*fact(a-1);
    }
}
int main()
{
    int n, ans;
    cin>>n;
    ans = fact(n);
    cout<<ans<<endl;
}