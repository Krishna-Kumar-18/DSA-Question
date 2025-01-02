class Solution {
public:
    int maxScore(string s) 
    {
        int maxi = INT_MIN;

        int zero_sum = 0;
        int one_sum = 0;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='0')
            {
                zero_sum++;
            }
            else
            {
                one_sum++;
            }
        }

        int left_zero = 0;
        int left_one = 0;
        for(int i=0; i<s.length()-1; i++)
        {
            if(s[i] == '0')
            {
                left_zero++;
            }
            else
            {
                left_one++;
            }

            maxi = max(maxi, (left_zero+(one_sum-left_one)));
        }

        return maxi;
    }
};