class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long int sum = 0;
        int mini = INT_MAX;
        int neg_count = 0;

        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                sum += abs(matrix[i][j]);

                if(matrix[i][j]<0)
                {   
                    neg_count++;
                }

                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(neg_count%2==0)
        {
            return sum;
        }

        return sum-(2*mini);
    }
};