#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    int arr[10] = {4, 7, 10, 15, 20, 9, 40, 2, 3, 100};
    int k = 4; // find 4th smallest data

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < 10; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout<<k<<"th smallest element : "<<pq.top();

    return 0;
}