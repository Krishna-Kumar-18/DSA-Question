class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            ans = min(ans, nums[i]);
        }
        return ans;
    }
};


// another approach using Binary Search

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        int mid = low + (high-low)/2;

        while(low < high)
        {   if(nums[mid]==nums[high])
            {
                if(nums[low]==nums[mid])
                {
                    low++;
                    high--;
                }
                else
                {
                    high = mid;
                }
            } 
            else if(nums[mid] > nums[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
            mid = low + (high-low)/2;
        }
        return nums[high];
    }
};