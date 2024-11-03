                                                                    // Top - Down Approach

class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>&dp)
    {
        if(ind==0)
        {
            return nums[ind];
        }

        if(ind<0)
        {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int pick = nums[ind] + solve(nums, ind-2, dp);
        int non_pick = 0 + solve(nums, ind-1, dp);

        dp[ind] = max(pick, non_pick);

        return dp[ind];
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int>dp(n+1, -1);

        int ans = solve(nums, n-1, dp);

        return ans;
    }
};


                                                                    // Bottom - UP Approach

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int>dp(n, 0);

        dp[0] = nums[0];

        int pick = INT_MIN;
        for(int i=1; i<n; i++)
        {
            if(i-2<0)
            {
                pick = nums[i] + 0;
            }
            else
            {
                pick = nums[i] + dp[i-2];
            }

            int non_pick = 0 + dp[i-1];
 
            dp[i] = max(pick, non_pick);
        }

        return dp[n-1];
    }
};



                                                                    // Space Optimization


class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        int prev = nums[0];
        int prev_2 = 0;

        int pick = INT_MIN;
        for(int i=1; i<n; i++)
        {
            if(i-2<0)
            {
                pick = nums[i] + 0;
            }
            else
            {
                pick = nums[i] + prev_2;
            }

            int non_pick = 0 + prev;
 
            int curr = max(pick, non_pick);

            prev_2 = prev;
            prev = curr;
        }

        return prev;
    }
};