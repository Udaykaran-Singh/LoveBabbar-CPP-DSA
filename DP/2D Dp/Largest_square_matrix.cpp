#include <iostream>
using namespace std;

int solve(vector< vector<int> > &mat, int i, int j, int &maxi){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }

    int right = solve(mat, i, j+1, maxi);
    int diagonal = solve(mat, i+1, j+1, maxi);
    int down = solve(mat, i+1, j, maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else{
        return 0;
    }

}

int solve_mem(vector< vector<int> > &mat, int i, int j, int &maxi, vector<vector<int> > &dp){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }

    // step 3
    if(dp[i][j] != -1) return dp[i][j];

    int right = solve_mem(mat, i, j+1, maxi, dp);
    int diagonal = solve_mem(mat, i+1, j+1, maxi, dp);
    int down = solve_mem(mat, i+1, j, maxi, dp);
    
    // step 2
    if(mat[i][j] == 1){
        int dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else{
        return dp[i][j] = 0;
    }

}

int solve_tab(vector< vector<int> > &mat, int n, int m, int &maxi){
    vector<vector<int> > dp(n + 1, vector<vector<int> >(m + 1, 0));
    
    for(int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0 ; j--){
            
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else{
                dp[i][j] =  0;
            }

            next = curr;
        }
        
    }

    return maxi;

}

int solve_space_optimise(vector< vector<int> > &mat, int n, int m, int &maxi){
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);
    
    for(int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0 ; j--){
            
            int right = curr[j+1];
            int diagonal = next[j+1];
            int down = next[j];

            if(mat[i][j] == 1){
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else{
                dp[i][j] =  0;
            }
        }
        
    }

    return maxi;

}

int maxSquare(int n, int m, vector< vector<int> > mat){
    // simiple
    int maxi = 0;
    solve(mat, 0, 0, maxi);
    return maxi;

    // recursion + memorization
    int maxi = 0;
    vector<vector<int> > dp(n, vector<int>(m, -1));
    solve_mem(mat, 0, 0, maxi, dp);
    return maxi;
}

int main(){
    
    return 0;
}