#include <iostream>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    vector<int> store;
    int arr[4] = {1, 2, 3, 4};
    int k = 3;

    for (int i = 0; i < 4; i++){
        int sum = 0;
        for (int j = i; j < 4; j++){
            sum += arr[j];
            store.push_back(sum);
        }
    }

    sort(store.begin(), store.end());

    cout<<store[store.size() - k]<<endl;




    // method 2

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < 4; i++){
        int sum = 0;
        for (int j = i; j < 4; j++){
            sum += arr[j];
            if(pq.size() < k) pq.push(sum);
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    cout<<pq.top()<<endl;

    
    return 0;
}