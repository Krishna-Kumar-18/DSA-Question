class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<int>highest;
        vector<int>smallest(n, 0);

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
            highest.push_back(maxi);
        }

        for(int i=n-1; i>=0; i--)
        {
            mini = min(mini, nums[i]);
            smallest[i] = mini;
        }

        int ans = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int max_ele = highest[i];
            int min_ele = smallest[i];

            if(max_ele-min_ele <= k)
            {
                ans = min(ans, i);
            }
        }

        if(ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};