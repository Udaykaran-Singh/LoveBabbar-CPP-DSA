#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> w;
    w.push(1);
    w.push(2);
    w.push(3);
    w.push(4);

    while (!w.empty())
    {
        cout<<w.top();
        w.pop();
    }
    
}