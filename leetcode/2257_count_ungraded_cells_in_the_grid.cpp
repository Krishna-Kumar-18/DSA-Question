class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>>temp(m, vector<int>(n, -1));

        for(int i=0; i<walls.size(); i++)
        {
            int a = walls[i][0];
            int b = walls[i][1];

            temp[a][b] = 2;
        }

        for(int i=0; i<guards.size(); i++)
        {
            int a = guards[i][0];
            int b = guards[i][1];
            temp[a][b] = 1;
        }

        for(int i=0; i<guards.size(); i++)
        {
            int row_ind = guards[i][0];
            int col_ind = guards[i][1];

            int left = col_ind;
            int right = col_ind;

            right++;
            while(right<n && temp[row_ind][right]!=2)            
            {
                if(temp[row_ind][right] == 1)
                {
                    break;
                }
                temp[row_ind][right] = 3;
                right++;
            }

            left--;
            while(left>=0 && temp[row_ind][left]!=2)
            {
                if(temp[row_ind][left] == 1)
                {
                    break;
                }
                temp[row_ind][left] = 0;
                left--;
            }

            int up = row_ind;
            int down = row_ind;

            down++;
            while(down<m && temp[down][col_ind]!=2)
            {
                if(temp[down][col_ind]==1)
                {
                    break;
                }
                temp[down][col_ind] = 0;
                down++;
            }

            up--;
            while(up>=0 && temp[up][col_ind]!=2)
            {
                if(temp[up][col_ind]==1)
                {
                    break;
                }
                temp[up][col_ind] = 0;
                up--;
            }
        }

        int ans = 0;
        for(auto i : temp)
        {
            for(auto j : i)
            {
                if(j==-1)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};