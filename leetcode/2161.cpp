class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int>smaller;
        vector<int>larger;
        vector<int>equal;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < pivot)
            {
                smaller.push_back(nums[i]);
            }
            else if(nums[i] > pivot)
            {
                larger.push_back(nums[i]);
            }
            else
            {
                equal.push_back(nums[i]);
            }
        }   

        vector<int>ans;

        for(auto i : smaller)
        {
            ans.push_back(i);
        }

        for(auto i : equal)
        {
            ans.push_back(i);
        }

        for(auto i : larger)
        {
            ans.push_back(i);
        }

        return ans;
    }
};
