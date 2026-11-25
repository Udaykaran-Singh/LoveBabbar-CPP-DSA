#include<iostream>
#include<queue>
using namespace std;

void rev_que(queue<int> &que){

    if(que.empty()){
        return;
    }

    int temp = que.front();
    que.pop();

    rev_que(que);

    que.push(temp);

}

int main(){

    queue<int> q;

    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }cout<<endl;

    rev_que(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;


}