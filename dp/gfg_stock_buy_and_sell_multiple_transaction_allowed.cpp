class Solution {
  public:
    int solve(vector<int>&prices, int buy, int ind, vector<vector<int>>&dp)
    {
        if(ind==prices.size())
        {
            return 0;
        }
        
        if(dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }
        
        int profit = 0;
        
        if(buy)
        {
            profit = max(-prices[ind] + solve(prices, 0, ind+1, dp), 0 + solve(prices, 1, ind+1, dp));
        }
        else 
        {
            profit = max(prices[ind] + solve(prices, 1, ind+1, dp), 0 + solve(prices, 0, ind+1, dp));
        }
        
        dp[ind][buy] = profit;
        
        return dp[ind][buy];
    }
    
    int maximumProfit(vector<int> &prices) 
    {
        int n = prices.size();
        
        vector<vector<int>>dp(n, vector<int>(2, -1));
        
        int ans = solve(prices, 1, 0, dp);
        
        return ans;
    }
};




                                                                // Another Approach

class Solution {
  public:
    int maximumProfit(vector<int> &prices) 
    {
        int profit = 0;
        
        for(int i=0; i<prices.size()-1; i++)
        {
            if(prices[i+1]>prices[i])
            {
                profit += (prices[i+1]-prices[i]);
            }
        }
        
        return profit;
    }
};