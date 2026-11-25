#include <iostream>
using namespace std;

// Recursion Simple
int solve(vector<int>& cost, int n){
    // base case
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }

    int ans = min(solve(cost, n-1), solve(cost, n-2)) + cost[n];
    return ans
}


// Top Down
// TC -> O(n)
// SC -> 2*O(n)
int solve2(vector<int>& cost, int n, vector<int>& dp){
    // base case
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }

    // step 3
    if(dp[n] != -1){
        return dp[n];
    }

    // step 2
    dp[n] = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp)) + cost[n];
    return dp[n]
}


// Bottom Up
// TC -> O(n)
// SC -> O(n)
int solve3(vector<int>& cost, int n){
    // tabulation
    vector<int> dp(n+1);
    // step2: base case analyse

    dp[0] = cost[0];
    dp[1] = cost[1];

    // 3rd step
    for(int i = 2; i < n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);

}


// Space Optimization
// TC -> O(n)
// SC -> O(1)
int solve4(vector<int>& cost, int n){
    // space optimization
    vector<int> dp(n+1);
    // step2: base case analyse

    int prev2 = cost[0];
    int prev1 = cost[1];

    // 3rd step
    for(int i = 2; i < n; i++){
        int current = cost[i] + min(dp[i-1], dp[i-2]);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);

}


int minCostClimbingStares(vector<int>& cost){
    // simple :-
    int n = cost.size();
    // can be simplified
    int ans = min(solve(cost, n-1), solve(cost, n-2));
    return ans;



    // recursion + memory element :-
    int n = cost.size();
    // step 1
    vector<int> dp(n+1, -1);
    int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));



    // tabularion (Bottom Up):-
    int n = cost.size();
    return solve3(cost, n);



    // space optimization
    int n = cost.size();
    return solve(cost, n);
}

int main(){
    
    return 0;
}