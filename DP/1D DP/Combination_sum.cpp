#include <iostream>
using namespace std;

int solve(vecto<int> &nums, int tar){
    if(tar == 0) return 1;
    if(tar < 0) return 0;

    int ans = 0
    for(int i = 0; i < nums.size(); i++){
        ans += solve(nums, tar - nums[i]);
    }

    return ans;
}

int solve_mem(vecto<int> &nums, int tar, vector<int> &dp){
    if(tar == 0) return 1;
    if(tar < 0) return 0;

    // step 3
    if(dp[tar] != -1) return dp[tar];

    int ans = 0
    for(int i = 0; i < nums.size(); i++){
        ans += solve_mem(nums, tar - nums[i]), dp;
    }

    // step 2
    return dp[tar] = ans;
}

int solve_tab(vecto<int> &nums, int tar){
    vector<int> dp(tar+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= tar; i++){
        for(int j = 0; j < nums.size(); j++){
            if(tar - nums[j] >= 0){
                dp[i] += dp[tar - nums[j]];
            }
        }
    }
    
    return dp[tar];
}

int findWays(vector<int> &nums, int tar){
    // simple
    solve(nums, tar);

    // recursion + memorization
    vector<int> dp(tar+1, -1);
    solve_mem(nums, tar, dp);

    // tabulation 
    solve_tab(nums, tar);
}

int main(){
    
    return 0;
}