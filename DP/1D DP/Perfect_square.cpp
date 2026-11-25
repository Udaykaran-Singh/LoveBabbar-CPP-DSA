#include <iostream>
using namespace std;

int solve(int n){
    if(wt == 0) return 0;

    int ans = n;
    for(int i = 1; i*i < n; i++){
        ans = min(ans, solve(n - i*i)+ 1);
    }
    return ans;
}
 
int solve_mem(int n, vector<int> &dp){
    if(wt == 0) return 0;

    // step 3
    if(dp[n] != -1) return dp[n];

    int ans = n;
    for(int i = 1; i*i < n; i++){
        ans = min(ans, solve_mem(n - i*i)+ 1);
    }

    // step 2
    return dp[n] = ans;
}

int solve_tab(int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1; i*i < n; i++){
        for(int j = 1; j <= n; j++){
            if(i - j*j >= 0){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
    }
    return dp[n];
}

int min_squ(int n){
    // simple
    return solve(n, n);

    // recursion + memorization
    vector<int> dp(n + 1, -1);
    return solve_mem(n, dp);

}

int main(){
    
    return 0;
}