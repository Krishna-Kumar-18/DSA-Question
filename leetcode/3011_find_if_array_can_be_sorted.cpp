class Solution {
public:
    bool canSortArray(vector<int>& nums) 
    {
        unordered_map<int, int>mp;
        vector<int>temp = nums;

        sort(temp.begin(), temp.end());

        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        for(int i=0; i<temp.size(); i++)
        {
            int ele = temp[i];
            int ind = mp[ele];
            while(ind>i)
            {
                int num_1 = nums[ind];
                int num_2 = nums[ind-1];

                if(__builtin_popcount(num_1) == __builtin_popcount(num_2))
                {
                    swap(nums[ind], nums[ind-1]);
                }
                else 
                {
                    return false;
                }
                ind--;
            }
        }

        return true;
    }
};