class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) 
    {
        vector<long long int>ans;
        
        long long int prod = 1;
        
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                count++;
                if(count==2)
                {
                    break;
                }
                continue;
            }
            else
            {
                prod = prod * nums[i];
            }
        }
        
        if(count==2)
        {
            for(int i=0; i<nums.size(); i++)
            {
                ans.push_back(0);
            }
            return ans;
        }
        
        
        if(count==1)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]==0)
                {
                    ans.push_back(prod);
                }
                else
                {
                    ans.push_back(0);
                }
            }
            return ans;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            long long int p = prod/nums[i];
            ans.push_back(p);
        }
        return ans;
    }
};