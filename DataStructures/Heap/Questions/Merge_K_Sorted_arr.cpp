#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        int i;
        int j;
 
        node(int a, int b, int c) : data(a), i(b), j(c);
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

int main(){
    // do not run, just understand.


    priority_queue<int, vector<node*>, compare> minHeap;

    // step 1: saare kArrayay ke first elements insert kro
    for(int i = 0; i < k; i++){
        node* temp = new node(kArray[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // step 2:
    while(minHeap.size() > 0){
        node* temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < kArray[i].size()){
            node* next = new node(kArray[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return 0;
}