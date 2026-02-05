class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        vector<int>ans;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                ans.push_back(0);
            }
            else if(nums[i] > 0)
            {
                int temp = nums[i]%nums.size();

                int j = i + temp;

                if(j >= nums.size())
                {
                    j = j - nums.size();
                }

                ans.push_back(nums[j]);
            }
            else 
            {
                int temp = abs(nums[i])%nums.size();

                int j = i - temp;

                if(j < 0)
                {
                    j = nums.size() + j;
                }

                ans.push_back(nums[j]);
            }
        }

        return ans;
    }
};