
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.length();

        map<char, int>mp;

        int len = 0;
        int max_len = 0;
        
        int i=0, j=0;

        while(j<n)
        {
            if(mp[s[j]]==0)
            {
                len++;
                mp[s[j]]++;
            }
            else
            {
                while(mp[s[j]]!=0)
                {
                    len--;
                    mp[s[i]]--;
                    i++;
                }
                len++;
                mp[s[j]]++;
            }
            max_len = max(len, max_len);
            j++;
        }

        return max_len;
    }
};
