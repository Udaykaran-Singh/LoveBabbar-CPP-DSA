#include <iostream>
using namespace std;

long long int solve_space_optimization(vector<int> &nums){
    int n = nums.size();

    prev2 = nums[0];
    prev1 = nums[1];

    for(int i = 2; i < n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }

    return prev1; 
}

long long int houseRobber(vector<int> valueInHouse){
    int n = valueInHouse.size();

    if(n == 1) return valueInHouse[0];

    vector<int> first, second;

    for(int i = 0; i < n; i++){
        if(i != n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i != 0){
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solve_space_optimization(first), solve_space_optimization(second));
}

int main(){
    
    return 0;
}