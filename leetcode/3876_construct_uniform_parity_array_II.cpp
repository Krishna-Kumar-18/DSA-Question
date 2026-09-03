class Solution {
public:
    bool uniformArray(vector<int>& nums1) 
    {
        int n = nums1.size(); 

        bool flag_even = false;
        bool flag_odd = false;

        int min_odd = INT_MAX;
        int min_even = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if(nums1[i]%2==0)
            {
                flag_even = true;
                min_even = min(min_even, nums1[i]);
            }
            else
            {
                flag_odd = true;
                min_odd = min(min_odd, nums1[i]);
            }
        }

        if(flag_even && flag_odd)
        {
            if(min_even-min_odd < 1)
            {
                return false;
            }
        }

        return true;
    }
};