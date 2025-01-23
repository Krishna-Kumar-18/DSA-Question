class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int server = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                bool flag = false;
                if(grid[i][j] == 1)
                {
                    for(int k=j+1; k<m; k++)
                    {
                        if(grid[i][k] == 1)
                        {
                            server++;
                            flag = true;
                            break;
                        }
                    }

                    if(!flag)
                    {
                        for(int k=i+1; k<n; k++)
                        {
                            if(grid[k][j] == 1)
                            {
                                server++;
                                flag = true;
                                break;
                            }
                        }
                    }

                    if(!flag)
                    {
                        for(int k=i-1; k>=0; k--)
                        {
                            if(grid[k][j] == 1)
                            {
                                server++;
                                flag = true;
                                break;
                            }
                        }
                    }

                    if(!flag)
                    {
                        for(int k=j-1; k>=0; k--)
                        {
                            if(grid[i][k] == 1)
                            {
                                server++;
                                flag = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return server;
    }
};