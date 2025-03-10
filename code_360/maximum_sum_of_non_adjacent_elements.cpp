#include <bits/stdc++.h> 

int solve(vector<int>&nums, int ind, vector<int>&dp) 
{
    if(ind==0)
    {
        return nums[ind];
    }

    if(ind<0)
    {
        return 0;
    }

    if(dp[ind]!=-1)
    {
        return dp[ind];
    }

    int take = nums[ind] + solve(nums, ind-2, dp);
    int not_take = 0 + solve(nums, ind-1, dp);

    dp[ind] = max(take, not_take);

    return dp[ind];
}

int maximumNonAdjacentSum(vector<int> &nums)
{   
    int n = nums.size();

    vector<int>dp(n+1, -1);

    int ans = solve(nums, n-1, dp);

    return ans;
}