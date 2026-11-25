#include<iostream>
#include<queue>


using namespace std;
int main(){
    queue<string> uday;
    uday.push("Udaykaran");
    uday.push("Singh");
    uday.push("Sadioura");

    // .front()
    cout<<"front element : "<<uday.front()<<endl;
    // string a = uday.front();
    // cout<<a<<endl;

    // .pop()
    uday.pop();
    cout<<"now front element : "<<uday.front()<<endl;

    // .size()



}