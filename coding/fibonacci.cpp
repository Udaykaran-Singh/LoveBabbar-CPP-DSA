#include<iostream>
using namespace std;
int main()
{
    int a=0,b=1;
    int n;
    cout<<"Enter number :"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int num = a;
        a = b;
        b = a + num;
        cout<<num<<", ";
    }
    
    
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...
}