class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n = s.length();

        unordered_map<char, int>mp;

        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
        }

        int l=0;
        while(l<n && mp[s[l]]>=k)
        {
            l++;
        }

        if(l==n)
        {
            return l;
        }

        int left_sub = longestSubstring(s.substr(0, l), k);

        while(l<n && mp[s[l]]<k)
        {
            l++;
        }

        int right_sub = (l<n) ? longestSubstring(s.substr(l), k) : 0; 

        return max(left_sub, right_sub);
    }
};