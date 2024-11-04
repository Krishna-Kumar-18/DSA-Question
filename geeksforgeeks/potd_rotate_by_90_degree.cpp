void rotate(vector<vector<int> >& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    for(int i=0; i<n; i++)                                          // first find the transpose of the matrix
    {
        for(int j=0; j<i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for(int i=0; i<m/2; i++)
    {
        for(int j=0; j<n; j++)
        {
            swap(matrix[j][i], matrix[j][m-i-1]);
        }
    }
}   