#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans){

    // base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index+1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);


}

int main(){
    vector<int> nums ;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    // for(int i:nums){
    //     cout<<i<<" ";
    // }cout<<endl;
    vector<vector<int> > ans;
    vector<int> output;

    int index = 0;
    solve(nums, output, index, ans);

    cout<<"{ ";
    for(vector<int> row:ans){
        cout<<"{ ";
        for(int j: row){
            cout<<j<<", ";
        }cout<<" }, ";
    }cout<<" }"<<endl;


    return 0;
}