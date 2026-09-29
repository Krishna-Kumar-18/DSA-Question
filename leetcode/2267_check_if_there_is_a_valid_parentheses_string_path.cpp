class Solution {
public:
    bool solve(vector<vector<char>>&grid, int row, int col, int balance, vector<vector<vector<int>>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(row>=n || col>=m)
        {
            return false;
        }

        if(grid[row][col]=='(')
        {
            balance++;
        }
        else
        {
            balance--;
        }

        if(balance < 0)
        {
            return false;
        }

        if(row==n-1 && col==m-1)
        {
            return (balance == 0);
        }

        if(dp[row][col][balance] != -1)
        {
            return dp[row][col][balance];
        }
        
        int rem = (n - row - 1) + (m - col - 1);
        
        if(balance > rem)
        {
            dp[row][col][balance] = false;
        }

        bool down = solve(grid, row+1, col, balance, dp);
        bool right = solve(grid, row, col+1, balance, dp);

        return dp[row][col][balance] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(n+m+1, -1)));

        if(grid[0][0]==')')
        {
            return false;
        }

        if((n+m-1)%2!=0)
        {
            return false;
        }

        return solve(grid, 0, 0, 0, dp);
    }
};