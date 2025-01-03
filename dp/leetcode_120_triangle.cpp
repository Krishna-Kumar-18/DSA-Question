                                                                                    // Top Down Approach (Recursion that's why top-down)

class Solution {
public:
    int solve(vector<vector<int>>&triangle, int i, int j, vector<vector<int>>&dp)
    {
        if(i==triangle.size()-1)
        {
            return triangle[i][j];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int down = triangle[i][j] + solve(triangle, i+1, j, dp);
        int diagonal = triangle[i][j] + solve(triangle, i+1, j+1, dp);

        dp[i][j] = min(down, diagonal);

        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        int ans = solve(triangle, 0, 0, dp);

        return ans;
    }
};




                                                                                // Tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        for(int j=0; j<n; j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};                                                             





                                                                                // Space Optimization


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();

        vector<int>prev(n, 0);
        
        for(int j=0; j<n; j++)
        {
            prev[j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--)
        {
            vector<int>curr(n, 0);
            for(int j=i; j>=0; j--)
            {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j+1];

                curr[j] = min(down, diagonal);
            }
            prev = curr;
        }

        return prev[0];
    }
};                                                                            