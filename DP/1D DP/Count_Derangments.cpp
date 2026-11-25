#include <iostream>
using namespace std;

long long int solve(int n){
    // base case
    if(n == 1) return 0;
    if(n == 2) return 1;

    int ans = (n-1)*( solve(n-1) + solve(n-2));
    return ans;
}

long long int solve_mem(int n, vector<int> &dp){
    // base case
    if(n == 1) return 0;
    if(n == 2) return 1;

    // step 3
    if(dp[n] != -1) return dp[n];

    // step 2
    return dp[n] = (n-1) * (solve_mem(n-1, dp) + solve_mem(n-2, dp));
}

long long int solve_tab(int n){
    vector<int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    }

    return dp[n];
}

long long int solve_opt(int n){
    vector<int> dp(n+1, -1);
    int prev2 = 0;
    int prev1 = 2;

    for(int i = 3; i <= n; i++){
        int current = (i-1) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

long long int countDerangement(int n){
    // simple
    return solve(n);

    // recursion + memorization
    vector<int> dp(n + 1, -1);
    return solve_mem(n, dp);
}

int main(){
    
    return 0;
}