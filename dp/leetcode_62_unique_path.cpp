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




                                                                                // Tabulation


class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = 1;
                }
                else 
                {
                    int down = 0;
                    int right = 0;

                    if(i>0)
                    {
                        down = dp[i-1][j];
                    }

                    if(j>0)
                    {
                        right = dp[i][j-1];
                    }

                    dp[i][j] = down + right;
                }
                
            }
        }

        return dp[m-1][n-1];
    }
};




                                                                        // Space Optimization

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int>prev(n, 0);

        for(int i=0; i<m; i++)
        {
            vector<int>curr(n, 0);
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    curr[j] = 1;
                }
                else 
                {
                    int down = 0;
                    int right = 0;

                    if(i>0)
                    {
                        down = prev[j];
                    }

                    if(j>0)
                    {
                        right = curr[j-1];
                    }

                    curr[j] = down + right;
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};