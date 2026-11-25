#include<iostream>
#include<queue>

using namespace std;
int main(){     // sorted  {in max heap , greatest element at top (front)}

    // max heap formed
    priority_queue<int> maxhe;

    // min heap form like this
    priority_queue<int, vector<int>, greater<int> > minhe;

    // .pop() ; .push() ; .size() ; .top() ; .empty()

    maxhe.push(1);
    maxhe.push(3);
    maxhe.push(2);
    maxhe.push(0);

    int n = maxhe.size();
    for (int i = 0; i < n; i++)
    {
        cout<<maxhe.top()<<" ";
        maxhe.pop();
    }cout<<endl;
    



}