class Solution {
public:
    int binaryGap(int n) 
    {
        bool flag = true;
        int count = 0;
        int maxi = 0;
        int prev = 0;
        while(n>0)
        {
            int last_bit = n & 1;
            n = n >> 1;
            count++;

            if(last_bit == 1)
            {
                if(flag)
                {
                    flag = false;
                    prev = count;
                }
                else
                {
                    maxi = max(maxi, count-prev);
                    prev = count;
                }
            }
        }

        return maxi;
    }
};