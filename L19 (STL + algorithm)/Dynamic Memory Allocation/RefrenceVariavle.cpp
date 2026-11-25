#include<iostream>
using namespace std;

void inc(int& a){               // a is refrence variable here (pass not by value)
    a++;                        // Alias made.
}

int main(){                             // Aliasing
    int i = 5;
    // int& j = i;                         // j is alias name of i
    // cout<<"i : "<<i<<" j : "<<j<<endl;
    // i++;
    // cout<<"i : "<<i<<" j : "<<j<<endl;
    // j++;
    // cout<<"i : "<<i<<" j : "<<j<<endl;

    inc(i);
    cout<<i;


    return 0;
}