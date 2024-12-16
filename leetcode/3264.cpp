class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        int n = nums.size();

        while(k--)
        {
            int mini = INT_MAX;
            int ind = 0;
            for(int i=0; i<n; i++)
            {
                if(nums[i]<mini)
                {
                    mini = nums[i];
                    ind = i;
                }
            }

            nums[ind] = multiplier*nums[ind];
        }

        return nums;
    }
};