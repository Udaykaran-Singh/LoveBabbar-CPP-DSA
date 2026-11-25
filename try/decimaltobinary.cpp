#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int binary=0 , i = 0;
    while(num!=0)
    {
       binary += (num&1)*pow(10,i) ;
       i++; 
       num >>= 1;
    }
    cout<< binary<<endl;
    return 0;
}