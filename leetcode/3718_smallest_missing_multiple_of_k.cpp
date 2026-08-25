class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        int count = 1;
        int mul = k*1;
        
        while(true)
        {
            if(find(nums.begin(), nums.end(), mul) == nums.end())
            {
                return mul;
            }
            count++;
            mul = k*count;
        }    
        return 1;
    }
};