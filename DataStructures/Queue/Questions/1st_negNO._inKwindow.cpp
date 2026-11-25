#include<iostream>
#include<queue>
using namespace std;

void first_neg_in_Kwindow(int arr[], int &k, queue<int> &ans){
    
    deque<int> dq;
    // storing index of element smaller than 0
    for (int i = 0; i < k; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    // storing ans
    if(dq.size() > 0){
        ans.push(arr[dq.front()]);
    }else{
        ans.push(0);
    }

    // processing remaining windows
    for (int i = k; i < 8; i++){

        // removal
        if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }

        // addition
        if(arr[i] < 0){
            dq.push_back(i);
        }

        // store ans
        if(dq.size() > 0){
            ans.push(arr[dq.front()]);
        }else{
            ans.push(0);
        }    
    }
    
}


int main(){

    int arr[8] = {-8, 2, -3, 23, 6, 5, -6, 10};
    int k = 2;
    queue<int> ans;

    first_neg_in_Kwindow(arr, k, ans);

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }cout<<endl;


}