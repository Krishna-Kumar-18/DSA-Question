#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) 
{
    unordered_map<long long, int>mp;

    int n = a.size();

    int len = 0;

    long long sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += a[i];

        if(sum == k)
        {
            len = max(len, i+1);
        }
        else if(sum>k)
        {
            long long ele = sum-k;
            if(mp.find(ele) != mp.end())
            {
                len = max(i-mp[ele], len);
            }
        }
        
        if(mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return len;
}