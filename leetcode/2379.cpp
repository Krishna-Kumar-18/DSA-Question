class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int white = 0;
        int black = 0;

        int ans = INT_MAX;
        
        int j=0;
        int i=0;

        while(j<blocks.size())
        {
            if(blocks[j] == 'W')
            {
                white++;
            }

            if(j-i+1==k)
            {
                ans = min(ans, white);

                if(blocks[i] == 'W')
                {
                    white--;
                    if(white<0)
                    {
                        white = 0;
                    }
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};
