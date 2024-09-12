class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        map<char, int>mp;

        int ans = 0;
        for(int i=0; i<allowed.length(); i++)
        {
            mp[allowed[i]]++;
        }

        for(int i=0; i<words.size(); i++)
        {
            string s = words[i];

            for(int j=0; j<s.length(); j++)
            {
                if(mp[s[j]]==0)
                {
                    break;
                }
                else if(j==s.length()-1)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};