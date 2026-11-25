#include<iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cout<<"Enter the Number you want to convert to BINARY :";
    cin>>n;
    int num = n;
    while (num!=0)
    {
        num/=2;
        count++;
    }
    int arr[count];
    int i = 0;
    // cout<<num<<endl;
    while (n!=0)
    {
        arr[i]=(n%2);
        n/=2;
        i++;
    }
    for (int i = count-1; i >= 0; i--)
    {
        cout<<arr[i]<<' ';
    }
    
    return 0;

}