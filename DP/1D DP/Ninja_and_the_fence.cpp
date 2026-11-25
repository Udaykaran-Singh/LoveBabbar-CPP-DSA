#include <iostream>
using namespace std;

int add(int a, int b){
    return a+b;
}

int mul(int a, int b){
    return a*b;
}

int solve(int n, int k){
    // base case
    if(n == 1) return k;

    if(n == 2) return add(k, mul(k, k-1));

    int ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));

    return ans;
}

int solve_mem(int n, int k, vector<int> &dp){
    // base case
    if(n == 1) return k;
    if(n == 2) return add(k, mul(k, k-1));

    // step 3
    if(dp[n] != -1) return dp[n];

    // step 2
    dp[n] = add(mul(solve_mem(n-2, k), k-1, dp), mul(solve_mem(n-1, k), k-1, dp));
    return dp[n];
}

int solve_tab(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i = 3; i <= n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }

    return dp[n];
}

int solve_space_optimize(int n, int k){
    prev2 = k;
    prev1 = add(k, mul(k, k-1));

    for(int i = 3; i <= n; i++){
        curr = add(mul(prev2, k-1), mul(prev1, k-1));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int number_of_ways(int n, int k){
    // simiple
    return solve(n, k);

    // recursion + memorization
    vector<int> dp(n+1, -1);
    solve_mem(n, k, dp);

}

int main(){
    
    return 0;
}