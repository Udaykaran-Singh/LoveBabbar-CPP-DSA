#include<iostream>
using namespace std;
int main()
{
    int a, sum=0;
    cout<<"Enter the NUMBER upto which you want to find the sum of Natural NuMBER :\n";
    cin>> a;
    // while (a!=0)
    // {
    //     sum = sum+a;
    //     a-=1;
    // }
    
    
    for (int i = 0; i <= a; i++)
    {
        sum += i ;
    }
    
    cout<< sum<<endl;
    // both the ways are correct.
    
}