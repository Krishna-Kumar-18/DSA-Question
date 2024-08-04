class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        set<int>s;

        for(auto i : nums)
        {
            s.insert(i);
        }

        set<int>temp;
        int ans = 0;

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i; j<nums.size(); j++)
            {
                temp.insert(nums[j]);
                if(temp.size()==s.size())
                {
                    ans++;
                }
            }
            temp.clear();
        }

        return ans;
    }
};