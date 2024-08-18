class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int>dp(n);
        dp[0] = 1;

        int pt_2 = 0;
        int pt_3 = 0;
        int pt_5 = 0;

        for(int i=1; i<n; i++)
        {
            int two_multiple = dp[pt_2] * 2;
            int three_multiple = dp[pt_3] * 3; 
            int five_multiple = dp[pt_5] * 5;

            dp[i] = min(two_multiple, min(three_multiple, five_multiple));

            if(dp[i] == two_multiple) 
            {
                pt_2++;
            }

            if(dp[i] == three_multiple)
            {
                pt_3++;
            }

            if(dp[i] == five_multiple)
            {
                pt_5++;
            }
        }

        return dp[n-1];
    }
};