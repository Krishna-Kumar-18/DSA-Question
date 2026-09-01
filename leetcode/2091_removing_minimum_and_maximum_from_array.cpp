class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int n = nums.size();

        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int ans = INT_MAX;

        int mini = min(minIndex, maxIndex);
        int maxi = max(minIndex, maxIndex);

        // if(mini >= nums.size()-mini-1)
        // {
        //     return nums.size()-mini;
        // }

        ans = min(ans, n-mini);

        int rem = maxi - mini;

        // if(rem >= nums.size()-maxi-1)
        // {
        //     return (mini + 1) + nums.size() - maxi;
        // }

        ans = min(ans, mini+1+n-maxi);


        ans = min(ans, mini+1+rem);
        //return (mini+1) + rem;

        return ans;
    }
};