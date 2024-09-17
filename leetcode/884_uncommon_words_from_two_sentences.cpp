class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        vector<string>ans;

        map<string, int>mp;

        string temp = "";
        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i]-'0'==-16)
            {
                mp[temp]++;
                temp = "";
            }
            else 
            {
                temp += s1[i];
            }
        }
        mp[temp]++;

        temp = "";
        for(int i=0; i<s2.length(); i++)
        {
            if(s2[i]-'0'==-16)
            {
                mp[temp]++;
                temp = "";
            }
            else 
            {
                temp += s2[i];
            }
        }
        mp[temp]++;

        for(auto i : mp)
        {
            if(i.second==1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};