class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int num = start^goal;

        int ans=0;
        for(int i=0; i<32; i++)
        {
            if(num&1)
            {
                ans++;
            }
            num = num >> 1;
        }
    
        return ans;
    }
}