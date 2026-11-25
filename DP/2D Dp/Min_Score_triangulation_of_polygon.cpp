#include <iostream>
using namespace std;

int solve(vector<int> &v, int i, int j){
    // base case
    if(i + 1 == j){
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++){
        ans = min(ans, v[i]*v[j]*v[k] + solve(v, i, k) + solve(v, k, j));
    }

    return ans;
    
}

int solve_mem(vector<int> &v, int i, int j, vector<vector<int> > &dp){
    // base case
    if(i + 1 == j){
        return 0;
    }

    // step 3
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++){
        ans = min(ans, v[i]*v[j]*v[k] + solve_mem(v, i, k, dp) + solve_mem(v, k, j, dp));
    }

    // step 2
    return dp[i][j] = ans;
}

int solve_tab(vector<int> &v){
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for (int i = n-1; i >= 0; i--){
        for (int j = i+2; j < n; j++){
          int ans = INT_MAX;
            for (int k = i + 1; k < j; k++){
                ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
            } 
            d[i][j] = ans;
        }
        
    }

    return dp[0][n-1];
    
}


int min_score_triangulation(vector<int> &values){
    // simple
    int n = values.size();
    return solve(values, 0, n-1);

    // recursion + memorization
    vector<vector<int> > dp(n, vector<int>(n, -1));
    solve_mem(values, 0, n-1, dp)
}

int main(){
    
    return 0;
}

// by student
int minSideJumps(vector<int>& obstacles) {
        //BFS lago
        queue <pair<pair<int,int>,int>> q;
        q.push({{2,0},0});
        int ans=INT_MAX;
        vector<vector<int>> visited(4,vector<int>(obstacles.size(),INT_MAX));
        visited[2][0]=0;
        while(!q.empty())
        {
            int lane=q.front().first.first;
            int index=q.front().first.second;
            int level=q.front().second;
            //cout<<lane<<" "<<index<<endl;
            q.pop();
            if(index==obstacles.size()-1){
            ans=min(ans,level);
            continue;
            }
            for(int i=1;i<=3;i++)
            {
                if(lane!=i && level+1<visited[i][index] && obstacles[index]!=i)
                {
                q.push({{i,index},level+1});
                visited[i][index]=level+1;
                }
                else if(lane==i && level<visited[i][index+1] && obstacles[index+1]!=i)
                {
                q.push({{i,index+1},level});
                visited[i][index+1]=level;
                }
            }
        }
        return ans;
    }