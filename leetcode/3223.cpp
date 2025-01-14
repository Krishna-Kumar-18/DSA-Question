class Solution {
public:
    int minimumLength(string s) 
    {
        int n = s.length();

        unordered_map<int, int>mp;

        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
        }

        int mini = 0;

        for(auto i : mp)
        {
            if(i.second >= 3)
            {
                int freq = i.second;
                while(freq >= 3)
                {
                    freq -= 2;
                }

                mini += freq;
            }
            else
            {
                mini += i.second;
            }
        }

        return mini;
    }
};