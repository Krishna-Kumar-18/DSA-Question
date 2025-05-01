class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int count = 0;

        for(int i=0; i<nums.size()-2; i++)
        {
            int sum = nums[i] + nums[i+2];
            
            if(nums[i+1]%2 == 0)
            {
                if(sum == nums[i+1]/2)
                {
                    count++;
                }
            }
        }

        return count;
    }
};
