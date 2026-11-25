#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter a Alphabet :\n";
    int a ;
    a = cin.get();
    // cout << a <<endl; 
    if (a>=int('A') && a<=int('Z'))
    {
        cout << "CAPITAL";
    }
    else if (a>=int('a') && a<=int('z')){
        cout<<"small";
    }
    else if (a>=int('0') && a<=int('9'))
    {
        cout<<"Numeric\n";
    }
    else{
        cout << "neither Capital nor Small nor Numeric\n";
    }
}