class Solution {
  public:
    void solve(vector<string>&ans, vector<vector<int>>&maze, string &temp, vector<vector<int>>&vis, int row, int col, int n)
    {
        if(row==n-1 && col==n-1)
        {
            ans.push_back(temp);
            return;
        }
        
        //down
        if(row+1 < n)
        {
            if(maze[row+1][col]==1 && vis[row+1][col]==0)
            {
                vis[row+1][col] = 1;
                temp += 'D';
                solve(ans, maze, temp, vis, row+1, col, n);
                temp.pop_back();
                vis[row+1][col] = 0;
            }
        }
        
        //left
        if(col-1 >= 0)
        {
            if(maze[row][col-1]==1 && vis[row][col-1]==0)
            {
                vis[row][col-1] = 1;
                temp += 'L';
                solve(ans, maze, temp, vis, row, col-1, n);
                temp.pop_back();
                vis[row][col-1] = 0;
            }
        }
        
        //right
        if(col+1 < n)
        {
            if(maze[row][col+1]==1 && vis[row][col+1]==0)
            {
                vis[row][col+1] = 1;
                temp += 'R';
                solve(ans, maze, temp, vis, row, col+1, n);
                temp.pop_back();
                vis[row][col+1] = 0;
            }
        }
        
        //up
        if(row-1 >= 0)
        {
            if(maze[row-1][col]==1 && vis[row-1][col]==0)
            {
                vis[row-1][col] = 1;
                temp += 'U';
                solve(ans, maze, temp, vis, row-1, col, n);
                temp.pop_back();
                vis[row-1][col] = 0;
            }
        }
        
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) 
    {
        vector<string>ans;
        string temp = "";
        
        int n = maze.size();
        
        vector<vector<int>>vis(n, vector<int>(n, 0));
        
        
        if(maze[0][0] == 1)
        {
            vis[0][0] = 1;
            solve(ans, maze, temp, vis, 0, 0, n);
        }
        
        return ans;
    }
};