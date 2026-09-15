class Solution {
public:
    bool isPalindrome(string &s, int start, int end, vector<vector<int>>&pal)
    {
        if(start>=end)
        {
            return true;
        }

        if(pal[start][end]!=-1)
        {
            return pal[start][end];
        }

        if(s[start]!=s[end])
        {
            return pal[start][end] = false;
        }

        return pal[start][end] = isPalindrome(s, start+1, end-1, pal);
    }

    int solve(string &s, int k, int i, vector<int>&dp, vector<vector<int>>&pal)
    {
        if(i >= s.size())
        {
            return 0;
        }

        if(dp[i] != -1)
        {
            return dp[i];
        }

        int ans = solve(s, k, i+1, dp, pal);

        for(int j=i; j<s.size(); j++)
        {
            if(j-i+1>=k && isPalindrome(s, i, j, pal))
            {
                ans = max(ans, 1+solve(s, k, j+1, dp, pal));
            }
        }

        dp[i] = ans;

        return dp[i];
    }

    int maxPalindromes(string s, int k) 
    {
        int n = s.size();

        vector<int>dp(n, -1);
        vector<vector<int>>pal(n, vector<int>(n, -1));

        return solve(s, k, 0, dp, pal);
    }
};