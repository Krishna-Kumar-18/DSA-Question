class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        vector<int>ans;

        for(int i=0; i<matrix.size(); i++)
        {
            int mini = INT_MAX;
            int ind = -1;
            for(int j=0; j<matrix[0].size(); j++)
            {
                mini = min(matrix[i][j], mini);
                if(mini == matrix[i][j])
                {
                    ind = j;
                }
            }
            
            int maxi = INT_MIN;
            for(int k=0; k<matrix.size(); k++)
            {
                maxi = max(matrix[k][ind], maxi);
            }

            if(mini == maxi)
            {
                ans.push_back(mini);
            }
        }
        return ans;
    }
};  