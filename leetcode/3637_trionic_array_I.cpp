class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int count = 0;
        int i=0;

        while(nums[i] < nums[i+1])
        {
            if(count == 0)
            {
                count++;
            }
            i++;
            if(i==nums.size()-1)
            {
                return false;
            }
        }

        if(count == 0)
        {
            return false;
        }

        while(nums[i] > nums[i+1])
        {
            if(count == 1)
            {
                count++;
            }
            i++;
            if(i==nums.size()-1)
            {
                return false;
            }
        }

        if(count == 1)
        {
            return false;
        }

        while(nums[i] < nums[i+1])
        {
            i++;
            if(i==nums.size()-1)
            {
                return true;
            }
        }

        if(i!=nums.size()-1)
        {
            return false;
        }

        return true;
    }
};