#include <iostream>
using namespace std;

int solve(vector<int> &satisfaction, int index, int time){
    // base case
    if(index == satisfaction.size()) return 0;

    int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);
    int exclude = 0 + solve(satisfaction, index + 1, time);

    return max(include, exclude);
}

int solve_mem(vector<int> &satisfaction, int index, int time, vector<vector<int> > &dp){
    // base case
    if(index == satisfaction.size()) return 0;

    // step 3
    if(dp[index][time] != -1) return dp[index][time];

    int include = satisfaction[index] * (time + 1) + solve_mem(satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + solve_mem(satisfaction, index + 1, time, dp);

    // step 2
    return dp[index][time] = max(include, exclude);
}

int solve_tab(vector<int> &satisfaction){

    int n = satisfaction.size();
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

    for (int index = n-1; index >= 0; index--){
        for (int time = n-1; time >= 0; time--){

            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];
            dp[index][time] = max(include, exclude);
        }
        
    }
    

    return dp[0][0];
}

int solve_space_optimize(vector<int> &satisfaction){

    int n = satisfaction.size();
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for (int index = n-1; index >= 0; index--){
        for (int time = n-1; time >= 0; time--){

            int include = satisfaction[index] * (time + 1) + next[time + 1];
            int exclude = 0 + next[time];
            curr[time] = max(include, exclude);
        }
        
    }
    

    return next[0];
}

int maxSatisFaction(vector<int> &satisfaction){
    // simple
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 0);

    // recrusion + memorization
    int n = satisfaction.size();
    vector<vector<int> > dp(n+!, vector<int>(n+1, -1));
    return solve_mem(satisfaction, 0, 0, dp);
}

int main(){
    
    return 0;
}

// greedy algo by students
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    int ans=0;
    for(int i=0;i<satisfaction.size();i++){
        int sum=0;
        int count=1;
        for(int j=i;j<satisfaction.size();j++){
            sum+=satisfaction[j]*count;
            count++;
        }
    ans=max(ans,sum);
    }
    return ans;
}
 
