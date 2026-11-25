#include<iostream>
using namespace std;
int main()
{
    int ch;
    cin>>ch;
    while (1)
    {
        // exit(ch);
        switch (ch)
        {
            case 1:
                cout<<"hello how are you?";
                           // break only take us outside the switch case not while.
                break;     // break will take us outside the switch otherwise all the cases will run.
                // continue;  // continue will do nothing  
                              // we connot use continue in switch casse. 
        
            default:
                cout<<"not now.";
                break;
        }
        
    }
    
}