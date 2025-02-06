class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int maxi = INT_MIN;
        bool flag = true;
        int count = 0;
        int mini = INT_MIN;

        if(nums.size() == 1){
            return 1;
        }

        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] < nums[i+1])
            {
                if(flag)
                {
                    count += 2;
                    flag = false;
                }
                else {
                    count++;
                }
            }
            else{
                count = 0;
                flag = true;
            }
            maxi = max(count, maxi);
        }

        flag = true;
        count = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(flag)
                {
                    count += 2;
                    flag = false;
                }
                else {
                    count++;
                }
            }
            else{
                count = 0;
                flag = true;
            }
            mini = max(mini, count);
        }

        if(maxi==0 && mini==0)
        {
            return 1;
        }
        return max(mini, maxi);
    }
};