class Solution {
public:
    int subarraySum(vector<int>& a, int k) 
    {
        unordered_map<long long, int>mp;

        int n = a.size();

        mp[0] = 1;

        int count = 0;

        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += a[i];

            long long  ele = sum - k;

            count += mp[ele];

            mp[sum]++;
        }
        return count;
    }
};