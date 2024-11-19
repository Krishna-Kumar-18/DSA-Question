class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<long long int, long long int>mp;

        int n = nums.size(); 
        int i=0, j=0;
        long long int ans = INT_MIN;
        long long int sum = 0;

        int count = 0;
        while(i<n)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
            {
                while(mp[nums[i]]>1)
                {
                    sum -= nums[j];
                    mp[nums[j]]--;
                    j++;
                    count--;
                }
            }

            sum += nums[i];
            count++;
            i++;

            if(count == k)
            {
                ans = max(ans, sum);
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
                count--;
            }
        }

        if(ans == INT_MIN)
        {
            return 0;
        }

        return ans;
    }
};