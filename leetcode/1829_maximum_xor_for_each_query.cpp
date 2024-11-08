class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int>ans;

        for(int i=1; i<nums.size(); i++)
        {
            nums[i] = nums[i-1] ^ nums[i];
        }

        int kmax = (1<<maximumBit)-1;

        for(int i=nums.size()-1; i>=0; i--)
        {
            ans.push_back(nums[i]^kmax);
        }

        return ans;
    }
};