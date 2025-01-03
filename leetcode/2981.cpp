class Solution {
public:
    int maximumLength(string s) 
    {
        map<pair<char, int>, int>mp;

        int n = s.length();

        int max_len = 0;

        for(int i=0; i<n; i++)
        {
            int len = 1;
            mp[{s[i], len}]++;
            for(int j=i+1; j<n; j++)
            {
                if(s[j] == s[j-1])
                {
                    len++;
                    mp[{s[i], len}]++;
                }
                else 
                {
                    break;
                }
            }

            if(mp[{s[i], len}]>=3)
            {
                max_len = max(max_len, len);
            }
        }

        return (max_len==0) ? -1 : max_len;
    }
};