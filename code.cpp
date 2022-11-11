#include <bits/stdc++.h>  
int rec(vector<int>&nums, int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }
    int include = rec(nums, n-2) + nums[n];
    int exclude = rec(nums, n-1) + 0;
    
    return max(include, exclude);
    
}
int solveMem(vector<int> &nums, int n, vector<int>&dp){
//     step3 base case analyse
    if(n < 0){
        return -1;
    }
    if(n==0){
           return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
     int include = rec(nums, n-2) + nums[n];
    int exclude = rec(nums, n-1) + 0;
//     step2
    dp[n] = max(include, exclude);
    return dp[n];
    
}

int solveTab(vector<int> &nums){

       
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    
   for(int i=1; i<n;i++){
       int include = dp[i-2]+nums[i];
       int exclude = dp[i-1]+0;
       dp[i] = max(include, exclude);
   }
    return dp[n-1];
    
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
//     return rec(nums, nums.size()-1);
//     using memoziation

    //     vector<int> dp(nums.size()+1, -1);
//     return solveMem(nums, nums.size()-1, dp);
    
//     using tabulation
    return solveTab(nums);
    
    
}