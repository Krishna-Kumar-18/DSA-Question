class Solution {
  public:
    void check(vector<vector<int>>&mat, vector<string>&ans, int n, int i, int j, string temp)
    {
        if(i<0 || j<0 || i==n || j==n || mat[i][j]!=1)
        {
            return;
        }
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(temp);
            return;
        }
        
        mat[i][j]=-1;
        
        check(mat, ans, n, i+1, j, temp+'D');
        check(mat, ans, n, i-1, j, temp+'U');
        check(mat, ans, n, i, j+1, temp+'R');
        check(mat, ans, n, i, j-1, temp+'L');
        
        mat[i][j]=1;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) 
    {
        vector<string>ans;
        
        int n = mat[0].size();
        
        if(mat[0][0] == 0)
        {
            ans.push_back("-1");
            return ans;
        }
        
        check(mat, ans, n, 0, 0, "");
        
        
        return ans;
    }
};