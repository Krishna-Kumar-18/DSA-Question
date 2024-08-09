class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        set<int>s;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(n-i < 3)
            {
                break;
            }
            for(int j=0; j<m; j++)
            {
                s.clear();
                bool flag = false;
                if(m-j < 3)
                {
                    break;
                }

                for(int k=i; k<i+3; k++)
                {
                    for(int l=j; l<j+3; l++)
                    {
                        if(grid[k][l]>0 && grid[k][l]<10)
                        {
                            s.insert(grid[k][l]);
                        }
                        else
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                    {
                        break;
                    }
                }

                if(flag)
                {
                    continue;
                }

                if(s.size()!=9)
                {
                    continue;
                }

                s.clear();
                for(int k=i; k<i+3; k++)
                {
                    int sum = 0;
                    for(int l=j; l<j+3; l++)
                    {
                        sum += grid[k][l];
                    }
                    s.insert(sum);
                    if(s.size()>1)
                    {
                        flag = true;
                        break;
                    }
                }

                if(flag)
                {
                    continue;
                }
                
                for(int k=j; k<j+3; k++)
                {
                    int sum = 0;
                    for(int l=i; l<i+3; l++)
                    {
                        sum += grid[l][k];
                    }
                    s.insert(sum);
                    if(s.size()>1)
                    {
                        flag = true;
                        break;
                    }
                }

                if(flag)
                {
                    continue;
                }

                int first_diagonal_sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int second_diagonal_sum = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

                s.insert(first_diagonal_sum);
                s.insert(second_diagonal_sum);

                if(s.size()>1)
                {
                    continue;
                }

                ans++;
            }
        }
        return ans;
    }
};