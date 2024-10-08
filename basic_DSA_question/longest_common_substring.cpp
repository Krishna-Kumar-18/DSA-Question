class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) 
    {
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        int res = 0;
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > res)
                    {
                        res = dp[i][j];
                    }
                }
            }
        }
        return res;
    }
};

                                                                // another approach


class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) 
    {
        int n = str1.length();
        int m = str2.length();
        
        vector<int>prev(m+1, 0), curr(m+1, 0);
        
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                    ans = max(curr[j], ans);
                }
                else 
                {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};

