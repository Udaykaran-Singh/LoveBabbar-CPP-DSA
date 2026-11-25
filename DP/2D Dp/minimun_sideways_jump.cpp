#include <iostream>
using namespace std;

int solve(vector<int> &obstacles, int currlane, int currpos, int &n){
    // base case
    if(currpos == n){
        return 0;
    }

    if(obstacles[currpos+1] != currlane){
        // no obstacle in current lane so move on
        return solve(obstacles, currlane, currpos+1, n);
    }
    else{
        // obstacle on current lane, now have to jump side wise
        ans = INT_MAX;
        for(int i = 1; i <= 3; i++){
            if(currlane != i && obstacles[currpos] != i){
                ans = min(ans, i + solve(obstacles, i, currpos, n));
            }
        }
        return ans;
    }
}

int solve_mem(vector<int> &obstacles, int currlane, int currpos, int &n, vector<vector<int> > &dp){
    // base case
    if(currpos == n){
        return 0;
    }

    // step 3
    if(dp[currlane][currpos] != -1) return dp[currlane][currpos];


    if(obstacles[currpos+1] != currlane){
        // no obstacle in current lane so move on
        return solve_mem(obstacles, currlane, currpos+1, n);
    }
    else{
        // obstacle on current lane, now have to jump side wise
        ans = INT_MAX;
        for(int i = 1; i <= 3; i++){
            if(currlane != i && obstacles[currpos] != i){
                ans = min(ans, i + solve_mem(obstacles, i, currpos, n));
            }
        }

        // step 2
        return dp[currlane][currpos] = ans;
    }
}


int solve_tab(vector<int> &obstacles, int &n){
    vector<vector<int> > dp(4, vector<int>(obstacles.size(), INT_MAX));

    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;
    dp[0][n] = 0;

    for(int i = n-1; i >= 0; i++){
        for(int k = 1; k <= 3; k++){
            if(obstacles[i+1] != k){
                // no obstacle in current lane so move on
                dp[k][i] = dp[k][i+1];
            }
            else{
                // obstacle on current lane, now have to jump side wise
                for(int j = 1; j <= 3; j++){
                    if(k != j && obstacles[i] != j){
                        dp[k][i] = min(dp[k][i], 1 + dp[j][i+1]);
                    }
                }
            }
        }
    }

    return min(dp[2][0], min(dp[1][0], dp[3][0]) + 1);
}


int minSideJumps(vector<int> &obstacles){
    // simple
    return solve(obstacles, 2, 0, obstacles.size());

    // recursion + memorization
    vector<vector<int> > dp(4, vector<int>(obstacles.size(), -1));
    solve_mem(obstacles, 2, 0, n, dp);
}

int main(){
    
    return 0;
}