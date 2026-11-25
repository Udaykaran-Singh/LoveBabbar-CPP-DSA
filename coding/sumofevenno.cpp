#include<iostream>
using namespace std;
int main()
{
    int a , sum=0;
    cout << "Enter a Number\n";
    cin >> a;
    while (a!=0)
    {
        if (a%2==0)
        {
            sum += a;
        }
        a-=1;
    }
    cout<<sum;
    
}