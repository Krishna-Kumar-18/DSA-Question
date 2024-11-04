                                                                        // Top Down Aprroach

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>&dp)
    {
        if(row==0 && col==0)
        {
            return 1;
        }

        if(row<0)
        {
            return 0;
        }

        if(col<0)
        {
            return 0;
        }

        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }

        int left = solve(row, col-1, dp);
        int up = solve(row-1, col, dp);

        dp[row][col] = left + up;

        return dp[row][col];
    }

    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m, vector<int>(n, -1));

        int ans = solve(m-1, n-1, dp);

        return ans;
    }
};