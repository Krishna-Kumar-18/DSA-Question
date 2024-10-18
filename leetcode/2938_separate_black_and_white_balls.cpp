                                            // based on two pointer approach

class Solution {
public:
    long long minimumSteps(string s) 
    {
        int n = s.length();

        vector<int>v;

        long long ind = -1;
        for(long long i=n-1; i>=0; i--)
        {
            if(s[i]!='1')
            {
                ind = i;
                break;
            }
        }

        if(ind==-1)
        {
            return 0;
        }

        for(long long i=ind; i>=0; i--)
        {
            if(s[i]=='1')
            {
                v.push_back(i);
            }
        }

        if(v.size()==0)
        {
            return 0;
        }

        long long ans = 0;

        for(long long i : v)
        {
            ans += (ind-i);
            ind--;
        }

        return ans;
    }
};