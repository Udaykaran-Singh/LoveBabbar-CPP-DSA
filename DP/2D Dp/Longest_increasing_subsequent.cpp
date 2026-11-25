#include <iostream>
using namespace std;

int solve(int n, int a[], int curr, int prev){
    // base case
    if(curr == n){
        return 0;
    }

    // include
    int take = 0;
    if(prev == -1 || a[curr] > a[prev]){
        take = 1 + solve(n, a, curr + 1, curr);
    }

    // exclude
    int not_take = 0 + solve(n, a, curr + 1, prev);

    return max(take, not_take);
}

int solve_mem(int n, int a[], int curr, int prev, vector<vector<int> > &dp){
    // base case
    if(curr == n){
        return 0;
    }

    // step 3
    if(dp[curr][prev+1] != -1) return dp[curr][prev];

    // include
    int take = 0;
    if(prev == -1 || a[curr] > a[prev]){
        take = 1 + solve_mem(n, a, curr + 1, curr, dp);
    }

    // exclude
    int not_take = 0 + solve_mem(n, a, curr + 1, prev, dp);

    // step 2
    return dp[curr][prev+1] = max(take, not_take);
}

int solve_tab(int n, int a[]){

    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    

    for(int curr = n - 1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= 0; prev--){
            
            // include
            int take = 0;
            if(prev == -1 || a[curr] > a[prev]){
                take = 1 + dp[curr + 1][curr + 1];
            }

            // exclude
            int not_take = 0 + dp[curr + 1][prev+1];

            dp[curr][prev+1] = max(take, not_take);
        }
    }

    return dp[0][0];
}

int solve_space_optimize(int n, int a[]){

    vector<int> currROW(n+1, 0);
    vector<int> nextROW(n+1, 0);
    

    for(int curr = n - 1; curr >= 0; curr--){
        for(int prev = curr - 1; prev >= 0; prev--){
            
            // include
            int take = 0;
            if(prev == -1 || a[curr] > a[prev]){
                take = 1 + nextROW[curr + 1];
            }

            // exclude
            int not_take = 0 + nextROW[prev+1];

            currROW[prev+1] = max(take, not_take);
        }
        nextROW = currROW;
    }

    return nextROW[0][0];
}

int solve_optimal(int n, int a[]){
    if(n == 0){
        return 0;
    }

    vector<int> ans;
    ans.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] > ans.back()){
            ans.push_back(a[i]);
        }
        else{
            // find index of just bada element in ans
            int index = lower_bound(ans.begin(), ans.end(), a[i] - ans.begin());
            ans[index] = a[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n, int a[]){
    // simple
    solve(n, a, 0, -1)

    // recursion + memorization
    vector<vector<int> > dp(n, vector<int>(n+1, -1));
    solve_mem(n, a, 0, -1, dp);
}

int main(){
    
    return 0;
}