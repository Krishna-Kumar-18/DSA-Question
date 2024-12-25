class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>temp(n, vector<int>(m, 1));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    temp[i][j] = 0;
                }
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(temp[i][j] == 0)
                {
                    int row = i;
                    int col = j;
                    
                    for(int k=0; k<m; k++)
                    {
                        mat[row][k] = 0;
                    }
                    
                    for(int k=0; k<n; k++)
                    {
                        mat[k][col] = 0;
                    }
                }
            }
        }
    }
};