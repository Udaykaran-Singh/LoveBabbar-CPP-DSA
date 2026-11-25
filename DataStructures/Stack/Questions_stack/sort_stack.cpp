#include<iostream>
#include<stack>
using namespace std;

void sort_rec(stack<int> &num, int n){

    if(num.empty() || n >= num.top()){
        num.push(n);
        return;
    }

    int temp = num.top();
    num.pop();

    sort_rec(num,n);

    num.push(temp);


}

void empty_rec(stack<int> &num){
    if(num.empty()){
        return;
    }

    int n = num.top();
    num.pop();

    empty_rec(num);

    sort_rec(num, n);

}

int main(){
    stack<int> num;

    num.push(9);
    num.push(27);
    num.push(4);
    num.push(13);
    num.push(2);
    num.push(17);

    empty_rec(num);

    while(!num.empty()){
        cout<<num.top()<<endl;
        num.pop();
    }

}