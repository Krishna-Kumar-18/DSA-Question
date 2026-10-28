class Solution {
public:
    int solve(vector<vector<int>>&grid, int row, int col, int x, vector<vector<vector<int>>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(row>=n || col>=m)
        {
            return INT_MAX;
        }

        x ^= grid[row][col];

        if(row==n-1 && col==m-1)
        {
            return x;
        }

        if(dp[row][col][x] != -1)
        {
            return dp[row][col][x];
        }

        int right = solve(grid, row, col+1, x, dp);
        int down = solve(grid, row+1, col, x, dp);

        return dp[row][col][x] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(1024, -1)));

        return solve(grid, 0, 0, 0, dp);
    }
};