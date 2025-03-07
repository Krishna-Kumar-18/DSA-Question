                                            // Same as LCS only S string is reversed

class Solution {
  public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s[i-1] == t[j-1])
        {
            dp[i][j] = 1 + solve(s, t, i-1, j-1, dp);
            return dp[i][j];
        }
        
        dp[i][j] = 0 + max(solve(s, t, i-1, j, dp), solve(s, t, i, j-1, dp));
        
        return dp[i][j];
    }
    
    int longestPalinSubseq(string &s) 
    {
        string t = s;
        
        reverse(t.begin(), t.end());
        
        int n = s.length();
        
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        
        int ans = solve(s, t, n, n, dp);
        
        return ans;
    }
};
