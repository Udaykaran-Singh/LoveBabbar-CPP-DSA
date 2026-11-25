#include<iostream>
#include<stack>

using namespace std;
int main(){
    stack<string> uday;
    uday.push("Udaykaran");
    uday.push("Singh");
    uday.push("Sadioura");

    //.pop()                               // cannot use element that is poped
    uday.pop();     // remove top element

    // .top()
    cout<<"now at top : "<<uday.top()<<endl;

    // .size() ; .empty()



    // string a = uday.top();
    // cout<<a<<endl;
} 