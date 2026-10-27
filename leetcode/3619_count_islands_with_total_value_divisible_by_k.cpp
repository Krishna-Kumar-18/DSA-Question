class Solution {
public:
    long long int dfs(vector<vector<int>>&grid, int row, int col, int n, int m)
    {
    	if(row<0 || row>=n || col<0 || col>=m)
    	{
    		return 0;
    	}

    	if(grid[row][col]==0)
    	{
    		return 0;
    	}

    	long long int val = grid[row][col];
    
    	grid[row][col] = 0;	

    	long long int up = dfs(grid, row-1, col, n, m);
    	long long int down = dfs(grid, row+1, col, n, m);
    	long long int left = dfs(grid, row, col-1, n, m);
    	long long int right = dfs(grid, row, col+1, n, m);

	    return up+down+left+right + val;
    }

    int countIslands(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        long long int mod = k;

        for(int i=0; i<n; i++)
        {
        	for(int j=0; j<m; j++)
        	{
        		if(grid[i][j]!=0)
        		{
        			if(dfs(grid, i, j, n, m)%mod == 0)
        			{
        				ans++;
        			}
        		}
        	}
        }

        return ans;
    }
};