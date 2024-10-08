class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        vector<int>temp;
        long long int mod = 1e9+7;
        for(int i=0; i<nums.size(); i++)
        {
            int sum = 0;
            for(int j=i; j<nums.size(); j++)
            {
                sum += nums[j];
                sum = sum%mod;
                temp.push_back(sum);
            }
        }

        sort(temp.begin(), temp.end());
        
        int ans = 0;
        for(int i=left-1; i<right; i++)
        {
            ans += temp[i];
            ans = ans%mod;
        }
        return ans;
    }
};