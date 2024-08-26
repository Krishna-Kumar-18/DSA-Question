class Solution {
  public:
    int solve(string &pattern, string &str, int j, int i, vector<vector<int>>&dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        
        if(j<0 && i>=0)
        {
            return false;
        }
        
        if(i<0 && j>=0)
        {
            for(int k=0; k<=j; k++)
            {
                if(pattern[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        if(pattern[j]==str[i] || pattern[j]=='?')
        {
            return dp[i][j] = solve(pattern, str, j-1, i-1, dp);
        }
        else if(pattern[j] == '*')
        {
            return dp[i][j] = solve(pattern, str, j-1, i, dp) || solve(pattern, str, j, i-1, dp);
        }
        else
        {
            return false;
        }
    }
    
    int wildCard(string pattern, string str) 
    {
        vector<vector<int>>dp(str.length(), vector<int>(pattern.length(), -1));
        
        return solve(pattern, str, pattern.length()-1, str.length()-1, dp);
    }
};