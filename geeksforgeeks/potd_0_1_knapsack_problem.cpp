class Solution {
  public:
    int solve(int W, vector<int>&wt, vector<int>&val, int n, int ind)
    {
        if(ind==n)
        {
            return 0;
        }
        
        int pick=0, non_pick=0;
        
        non_pick = solve(W, wt, val, n, ind+1);
        
        if(W>=wt[ind])
        {
            pick = val[ind] + solve(W-wt[ind], wt, val, n, ind+1);
        }
        
        return max(non_pick, pick);
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) 
    {
        int n = wt.size();
        
        return solve(W, wt, val, n, 0);
    }
};

// another approach using dp

class Solution {
  public:
    int solve(int W, vector<int>&wt, vector<int>&val, int n, int ind, vector<vector<int>>&dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
        if(dp[ind][W]!=-1)
        {
            return dp[ind][W];
        }
        
        int pick=0, non_pick=0;
        
        non_pick = solve(W, wt, val, n, ind+1, dp);
        
        if(W>=wt[ind])
        {
            pick = val[ind] + solve(W-wt[ind], wt, val, n, ind+1, dp);
        }
        
        return dp[ind][W] = max(non_pick, pick);
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) 
    {
        int n = wt.size();
        
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        
        return solve(W, wt, val, n, 0, dp);
    }
};