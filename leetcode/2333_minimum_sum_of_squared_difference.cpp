class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        int n = nums1.size();

        vector<int>freq(100001, 0);
        int maxDiff = INT_MIN;

        for(int i=0; i<n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
            maxDiff = max(maxDiff, diff);
        }

        int k = k1+k2;
        for(int i=maxDiff; i>0 && k>0; i--)
        {
            if(freq[i]==0)
            {
                continue;
            }

            int operations = min(k, freq[i]);

            freq[i] -= operations;
            freq[i-1] += operations;

            k -= operations;
        }


        long long int ans = 0;
        for(long long int i=1; i<=maxDiff; i++)
        {
            long long int f = freq[i];

            ans += ((i * i) * f);
        }

        return ans;
    }
};