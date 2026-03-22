class Solution {
public:
    bool solve(vector<vector<int>>&mat, vector<vector<int>>&target)
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

        for(int j=0; j<m/2; j++)
        {
            for(int i=0; i<mat.size(); i++)
            {
                swap(mat[i][j], mat[i][mat[0].size()-1-j]);
            }
        }

        return mat == target;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        bool flag = false;
        for(int i=0; i<4; i++)
        {
            flag = solve(mat, target);

            if(flag == true)
            {
                return true;
            }
        }

        return false;
    }
};