class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        vector<int>ans;

        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == 0)
            {
                continue;
            }
            else if(nums[i] == nums[i+1])
            {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }

        int zero = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zero++;
            }
            else
            {
                ans.push_back(nums[i]);
            }
        }

        while(zero--)
        {
            ans.push_back(0);
        }

        return ans;
    }
};
