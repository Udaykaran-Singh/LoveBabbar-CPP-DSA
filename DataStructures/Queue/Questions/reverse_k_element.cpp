#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    queue<int> que;
    stack<int> st;
    queue<int> rem;
    int k = 3;

    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.push(6);

    int i = 0;

    while(!que.empty() && i < k){
        st.push(que.front());
        que.pop();
        i++;
    }
    
    while (!que.empty()){
        rem.push(que.front());
        que.pop();
    }

    while(!st.empty()){
        que.push(st.top());
        st.pop();
    }

    while(!rem.empty()){
        que.push(rem.front());
        rem.pop();
    }
    
    while(!que.empty()){
        cout<<que.front()<<" ";
        que.pop();
    }cout<<endl;

    
    



}