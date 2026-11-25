#include <iostream>
#include <vector>
using namespace std;

// top-down : recursion and tabulation
int fib_top_down(int n, vector<int> &dp){
    // base case 
    if(n <= 1) return n;

    // step 3
    if(dp[n] != -1){
        return dp[n];
    }

    // step 2
    return dp[n] = fib_top_down(n-1, dp) + fib_top_down(n-2, dp);
}

// bottom-up : tabulation
int fib_bottom_up(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2]
    }

    return dp[n];
}

// save space : cunning technique
int fib_save_space(int n){
    int prev1 = 1;
    int prev2 = 0;

    if(n == 0) return prev2;

    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;

        // shift logic
        prev2 = prev1;
        prev1 = curr;
    }

    cout<<prev1;
}

int main(){

    // already done in recursion
    // f(n) = f(n-1) + f(n-2)

    /* problem :-

    in recursive call we repeatedly find the value upto base case,
    even if we have encountered the n-1 th and n-2 th number we will go
    upto n == 0 or n == 1 which is very time consuming . */

    /* Solution :- DP
    
    what we can do is to memorise the answer to the numbers that we have visited
    and directly fill the value when asked insted of finding again and again.*/

    int n;
    cin >> n;

    vector<int> dp(n + 1);

    cout<<fib(n, dp)<<endl;
    
    return 0;
}