class Solution {
public:
    long long countCommas(long long n) 
    {
        long long int ans = 0;

        for(long long int x=1000; x<=n; x*=1000)
        {
            ans += n - x + 1;
        }

        return ans;
    }
};