#include<iostream>
using namespace std;
int main()
{
    //     to pick Enter, tabspace, space  :
    // 1.  a = cin.get()

    // actually a = cin.get() takes Ascii value not what we enter.
    int a;
    cout << "a = cin.get()"<<endl;
    a = cin.get();
    cout << a <<endl;

    
    int b,c;
    cout << ("enter two Numbers :\n");
    cin>> b >>c;
    cout << b<<endl <<c<<"\n\n";

    //     here cin do not pick :-
    // 1.  Enter 
    // 2.  tabspace (\t)
    // 3.  space


    char any;
    cin>> any;           //if it is int and we enter char it will give 0
                         //if it is char and we enter int it will give 1st digit
    cout<< any<<"\n\n";
}