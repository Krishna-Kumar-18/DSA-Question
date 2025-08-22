class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) 
    {
        int n = grid.size(); 
        int m = grid[0].size();

        int left = INT_MAX;
        int right = 0;
        int up = INT_MAX;
        int down = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    left = min(j, left);
                    right = max(j, right);
                    up = min(i, up);
                    down = max(i, down);
                }
            }
        }
        
        int length = right-left+1;
        int breadth = down-up+1;

        return length*breadth;
    }
};