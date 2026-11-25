#include <iostream>
using namespace std;

int solve(vector<int> &nums, int n){
    // base case
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1) + 0;

    return max(incl, excl);
}

int solve_mem(vector<int> &nums, int n, vector<int> &dp){
    // base case
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    // step 3
    if(dp[n] != -1) return dp[n];

    int incl = solve_mem(nums, n-2) + nums[n];
    int excl = solve_mem(nums, n-1) + 0;

    // step 2
    return dp[n] = max(incl, excl);
}

int solve_tab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = nums[1];

    for(int i = 2; i < n; i++){
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp(n - 1); 
}

int solve_space_optimization(vector<int> &nums){
    int n = nums.size();

    prev2 = nums[0];
    prev1 = nums[1];

    for(int i = 2; i < n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }

    return prev1; 
}

int maxNonAdjSum(vector<int> &nums){
    // simple
    int n = nums.size();
    int ans = solve(nums, n-1);
    return ans;


    // recursion + memorization
    int n = nums.size();
    vector<int> dp(n , -1);
    int ans = solve_mem(nums, n-1, dp)


}

int main(){
    
    return 0;
}