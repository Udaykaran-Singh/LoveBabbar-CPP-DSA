#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the amount :";
    cin >> n;
    switch (1)
    {//1234             5367 
    case 1://12         53
    cout<<"No. of Rs 100 notes :"<<n/100<<endl;
    case 2://1           3
    cout<<"No. of Rs 20 notes :"<<(n%100)/20<<endl;
    case 3://1           0
    cout<<"No. of Rs 10 notes :"<<(n%100)%20/10<<endl;
    case 4://0           1
    cout<<"No. of Rs 5 notes :"<<((n%100)%20)%10/5<<endl;
    case 5://2           1
    cout<<"No. of Rs 2 notes :"<<((n%100)%20)%5/2<<endl;
    case 6://0           0
    cout<<"No. of Rs 1 notes :"<<(((n%100)%20)%5)%2/1<<endl;
    }
}