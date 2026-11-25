#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int> >& ans){
    
    // base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    } 

    for(int i = index; i < nums.size(); i++){
        swap( nums[i], nums[index]);
        solve( nums, index+1, ans);
        swap( nums[i], nums[index]);

    }
 
}

int main(){
    vector<vector<int> > ans;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    int index = 0;
    solve(nums, index, ans);

    cout<<"{";
    for(vector<int> i : ans){
        cout<<"[";
        for(int j:i){
            cout<<j<<",";
        }cout<<"],";
    }cout<<"}"<<endl;
}