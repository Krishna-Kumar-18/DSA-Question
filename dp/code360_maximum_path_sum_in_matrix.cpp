                                                                            // Top Down Approach


#include <bits/stdc++.h> 

int solve(vector<vector<int>>&matrix, int i, int j, vector<vector<int>>&dp)
{
    if(i==matrix.size()-1)
    {
        return matrix[i][j];
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int diagonal_left = INT_MIN;
    int diagonal_right = INT_MIN;
    int down = INT_MIN;

    if(j>0)
    {
        diagonal_left = matrix[i][j] + solve(matrix, i+1, j-1, dp);
    }

    down = matrix[i][j] + solve(matrix, i+1, j, dp);

    if(j<matrix[0].size()-1)
    {
        diagonal_right = matrix[i][j] + solve(matrix, i+1, j+1, dp);
    }

    dp[i][j] = max(diagonal_left, max(diagonal_right, down));

    return dp[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>>dp(n, vector<int>(m, -1));

    int ans = INT_MIN;
    for(int i=0; i<m; i++)
    {
        ans = max(ans, solve(matrix, 0, i, dp));
    }

    return ans;
}





                                                                            // Tabulation


#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>>dp(n, vector<int>(m, 0));

    for(int j=0; j<m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int diagonal_left = matrix[i][j];
            if(j>0)
            {
                diagonal_left += dp[i-1][j-1];
            }
            else 
            {
                diagonal_left += -1e8;
            }

            int diagonal_down = matrix[i][j] + dp[i-1][j];

            int digaonal_right = matrix[i][j];
            if(j<matrix[0].size()-1)
            {
                digaonal_right += dp[i-1][j+1];
            }
            else 
            {
                digaonal_right += -1e8;
            }

            dp[i][j] = max(diagonal_left, max(diagonal_down, digaonal_right));
        }
    }

    int ans = INT_MIN;
    for(int j=0; j<m; j++)
    {
        ans = max(ans, dp[n-1][j]);
    }

    return ans;
}







                                                                                // Space Optimization




#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int>prev(m, 0);

    for(int j=0; j<m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for(int i=1; i<n; i++)
    {
        vector<int>curr(m, 0);
        for(int j=0; j<m; j++)
        {
            int diagonal_left = matrix[i][j];
            if(j>0)
            {
                diagonal_left += prev[j-1];
            }
            else 
            {
                diagonal_left += -1e8;
            }

            int diagonal_down = matrix[i][j] + prev[j];

            int digaonal_right = matrix[i][j];
            if(j<matrix[0].size()-1)
            {
                digaonal_right += prev[j+1];
            }
            else 
            {
                digaonal_right += -1e8;
            }

            curr[j] = max(diagonal_left, max(diagonal_down, digaonal_right));
        }
        prev = curr;
    }

    int ans = INT_MIN;
    for(int j=0; j<prev.size(); j++)
    {
        ans = max(ans, prev[j]);
    }

    return ans;
}