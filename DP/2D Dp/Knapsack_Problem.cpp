#include <iostream>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
    // base case

    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index == 0){
        if(weigh[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(weight, value, index-1, capacity-weight[index]);
    }

    int exclude = 0 + solve(weight, value, index-1, capacity);

    return max(exclude, include);
}

int solve_mem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector,int> > &dp){
    // base case

    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index == 0){
        if(weigh[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    // step 3
    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }
    
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve_mem(weight, value, index-1, capacity-weight[index], dp);
    }

    int exclude = 0 + solve_mem(weight, value, index-1, capacity, dp);

    // step 2
    return dp[index][capacity] =  max(exclude, include);
}

int solve_tab(vector<int> &weight, vector<int> &value, int n, int capacity){
    // step 1
    vector<vector<int> > dp(n, vector<int>(capacity + 1, 0));

    // step 2 :- analyse base case
    for(int w = weight[0]; w <= capacity; w++){
        if(weigh[0] <= capacity){
            dp[0][w] =  value[0];
        }
        else{
            dp[0][w] = 0;
        }
    }

    // step 3 :- 
    for(int index = 1; index < n; index++){
        for(int w = 0; w < capacity; w++){

            int include = 0;

            if(weight[index] <= w){
                include = value[index] + dp[index-1][w-weight[index]];
            }
            int exclude = 0 + dp[index-1][w];

            dp[index][w] =  max(exclude, include);
        }
    }

    return dp[n-1][capacity];
    
}

int solve_space_optimize(vector<int> &weight, vector<int> &value, int n, int capacity){
    // step 1
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // step 2 :- analyse base case
    for(int w = weight[0]; w <= capacity; w++){
        if(weigh[0] <= capacity){
            prev[w] =  value[0];
        }
        else{
            prev[w] = 0;
        }
    }

    // step 3 :- 
    for(int index = 1; index < n; index++){
        for(int w = 0; w <= capacity; w++){

            int include = 0;

            if(weight[index] <= w){
                include = value[index] + prev[w-weight[index]];
            }
            int exclude = 0 + prev[w];

            curr[w] =  max(exclude, include);
        }

        prev = curr;
    }

    return prev[capacity];
    
}


int solve_space_optimize_max(vector<int> &weight, vector<int> &value, int n, int capacity){
    // step 1
    vector<int> curr(capacity + 1, 0);

    // step 2 :- analyse base case
    for(int w = weight[0]; w <= capacity; w++){
        if(weigh[0] <= capacity){
            curr[w] =  value[0];
        }
        else{
            curr[w] = 0;
        }
    }

    // step 3 :- 
    for(int index = 1; index < n; index++){
        for(int w = capacity; w >= 0; w--){

            int include = 0;

            if(weight[index] <= w){
                include = value[index] + curr[w-weight[index]];
            }
            int exclude = 0 + curr[w];

            curr[w] =  max(exclude, include);
        }

    }

    return curr[capacity];
    
}

int KnapSack(vector<int> weight, vector<int> value, int n, int maxWeight){
    // simple
    return solve(weight, value, n-1, maxWeight);

    // recursion + memorization
    vector<vector,int> > dp(n, vector<int>(maxWeight + 1, -1));
    return solve_mem(weight, value, n-1, maxWeight, dp);

    // tabulation
    return solve_tab(weight, value, n, maxWeight);
}

int main(){
    
    return 0;
}