    class Solution {
public:
    void rotate(vector<vector<int>>& mat) 
    {
        int n = mat.size(); 
        int m = mat[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i=0; i<m/2; i++)
        {
            for(int j=0; j<n; j++)
            {
                swap(mat[j][i], mat[j][m-i-1]);
            }
        }
    }
};