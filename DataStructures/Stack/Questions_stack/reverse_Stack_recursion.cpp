#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &num, int n){

    if(num.empty()){
        num.push(n);
        return;
    }

    int peek = num.top();
    num.pop();

    insert_at_bottom(num, n);

    num.push(peek);

}

void reve(stack<int> &num){

    if(num.empty()){
        return;
    }

    int n = num.top();
    num.pop();

    reve(num);

    insert_at_bottom(num , n);


}

int main(){
    stack<int> num;

    num.push(9);
    num.push(7);
    num.push(4);
    num.push(3);
    num.push(2);
    num.push(1);

    reve(num);

    while(!num.empty()){
        cout<<num.top()<<endl;
        num.pop();
    }

}