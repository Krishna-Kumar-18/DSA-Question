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