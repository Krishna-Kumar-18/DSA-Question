class Solution {
public:
    int numTeams(vector<int>& rating) 
    {
        int ans = 0;
        for(int i=0; i<rating.size(); i++)
        {
            int l_s=0, l_b=0, r_s=0, r_b=0;
            for(int j=i-1; j>=0; j--)
            {
                if(rating[i] > rating[j])
                {
                    l_s++;
                }
                else if(rating[i] < rating[j])
                {
                    l_b++;
                }
            }

            for(int j=i+1; j<rating.size(); j++)
            {
                if(rating[i] < rating[j])
                {
                    r_b++;
                }
                else if(rating[i] > rating[j])
                {
                    r_s++;
                }
            }

            ans += (l_s*r_b) + (l_b*r_s);
        }
        return ans;
    }
};