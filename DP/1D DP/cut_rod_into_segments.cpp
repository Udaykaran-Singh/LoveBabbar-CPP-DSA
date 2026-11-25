#include <iostream>
using namespace std;

int solve(int n, int &x, int &y, int &z){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    int a = solve(n-x, x, y, z);
    int b = solve(n-y, x, y, z);
    int c = solve(n-z, x, y, z);

    return max(a, b, c);
}

int solve_mem(int n, int &x, int &y, int &z, vector<int> &dp){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    // step 3
    if(dp[n] != -1) return dp[n];

    int a = solve(n-x, x, y, z, dp);
    int b = solve(n-y, x, y, z, dp);
    int c = solve(n-z, x, y, z, dp);

    // step 2
    return dp[n] = max(a, b, c);
}

int solve_tab(int n, int &x, int &y, int &z){
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++){
        if(i - x >= 0){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i - y >= 0){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        if(i - z >= 0){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }
    
    if(dp[n] < 0){
        return 0;
    }
    return dp[n];

}

int cutSegments(int n, int x, int y, int, z){
    // simple
    int ans = solve(n, x, y, z);
    if(ans < 0){
        return 0;
    }
    return ans;

    // recursion + memorization
    vector<int> dp(n + 1, -1);
    int ans = solve_mem(n, x, y, z, dp);
    if(ans < 0){
        return 0;
    }
    return ans;
}

int main(){
    
    return 0;
}