class Solution {
public:
    int Z, O;
    int L, H;
    int l;

    int mod = 1e9+7;

    int solve(int l, vector<int>&dp)
    {
        if(l > H) 
        {
            return 0;
        }

        if(dp[l] != -1)
        {
            return dp[l];
        }

        bool add_one = false;
        if(l>=L && l<=H)
        {
            add_one = true;
        }

        int append_zero = solve(l+Z, dp);
        int append_one = solve(l+O, dp);

        dp[l] = (add_one + append_zero + append_one) % mod;

        return dp[l];
    }

    int countGoodStrings(int low, int high, int zero, int one) 
    {
        Z = zero;
        O = one;

        L = low;
        H = high;

        vector<int>dp(high+1, -1);

        return solve(0, dp);
    }
};