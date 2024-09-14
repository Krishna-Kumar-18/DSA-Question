class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxi = *max_element(nums.begin(), nums.end());

        int curr = 1;
        int ans = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]==nums[i-1] && nums[i]==maxi)
            {
                curr++;
                ans = max(ans, curr);
            }
            else
            {
                curr = 1;
            }
        }

        return ans;
    }
};