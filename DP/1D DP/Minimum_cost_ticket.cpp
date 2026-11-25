#include <iostream>
using namespace std;

int solve(int n, vector<int>& days, vector<int> &days, int index){
    // base case
    if(index >= n){
        return 0;
    }

    // 1 day
    int option1 = cost[0] + solve(n, days, cost, index+1);

    // 7 day pass
    int i = 0;
    for(int i = index; i < n && days[i] < days[index] + 7; i++);
        
    int option2 = cost[1] + solve(n, days, cost, i);

    // 30 days pass
    for(int i = index; i < n && days[i] < days[index] + 30; i++);
        
    int option3 = cost[1] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

int solve_mem(int n, vector<int>& days, vector<int> &days, int index, vector<int> &dp){
    // base case
    if(index >= n){
        return 0;
    } 

    // step 3
    if(dp[index] != -1) return dp[index];  



    // 1 day
    int option1 = cost[0] + solve_mem(n, days, cost, index+1, dp);
    // 7 day pass
    int i = 0;
    for(int i = index; i < n && days[i] < days[index] + 7; i++);   
    int option2 = cost[1] + solve_mem(n, days, cost, i, dp);
    // 30 days pass
    for(int i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = cost[1] + solve_mem(n, days, cost, i, dp);



    // step 2
    return dp[index] = min(option1, min(option2, option3));
}

int solve_tab(int n, vector<int>& days, vector<int> &days){
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
    
    for(int k = n-1; k >= 0; k--){
       // 1 day
        int option1 = cost[0] + dp[k+1];
        // 7 day pass
        int i = 0;
        for(int i = k; i < n && days[i] < days[k] + 7; i++);   
        int option2 = cost[1] + dp[i];
        // 30 days pass
        for(int i = k; i < n && days[i] < days[k] + 30; i++);
        int option3 = cost[1] + dp[i];

        dp[k] = min(option1, min(option2, option3));
 
    }

    return dp[0];
}

int solve_space_optimization(int n, vector<int> days, vector<int> cost){
    int ans = 0;

    queue<pair<int, int> > month;
    queue<pair<int, int> > week;

    for(int day : days){
        // step 1: remove expired days
        while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
        }

        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }

        // step 2: add cost for current day
        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));

        // step 3: ans update
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}

int min_cost(int n, vector<int> days, vector<int> cost){
    // simple
    return solve(n, days, cost, 0);

    // recursion + memorization
    vector<int> dp(n+1, -1);
    return solve_mem(n, days, cost, 0, dp);
}

int main(){
    
    return 0;
}