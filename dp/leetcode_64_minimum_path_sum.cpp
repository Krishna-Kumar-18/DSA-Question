                                                                                // Memoization

class Solution {
public:
    int solve(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            return grid[i][j];
        }

        if(i<0 || j<0)
        {
            return 1e9;
        } 

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int up = grid[i][j] + solve(grid, i-1, j, dp);
        int left = grid[i][j] + solve(grid, i, j-1, dp);

        dp[i][j] = min(left, up);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        int ans = solve(grid, n-1, m-1, dp);

        return ans;
    }
};




                                                                            // Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = grid[i][j];
                }
                else 
                {
                    int down = grid[i][j];
                    if(i>0)
                    {
                        down += dp[i-1][j];
                    }
                    else 
                    {
                        down += 1e9+7;
                    }

                    int right = grid[i][j];
                    if(j>0)
                    {
                        right += dp[i][j-1];
                    }
                    else 
                    {
                        right += 1e9+7;
                    }
                    dp[i][j] = min(down, right);
                }
            }
        }

        return dp[n-1][m-1];
    }
};