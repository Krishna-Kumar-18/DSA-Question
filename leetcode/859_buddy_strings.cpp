class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        bool flag = false;
        if(s.length() != goal.length())
        {
            return false;
        }

        if(s==goal)
        {
            flag = true;
        }

        int count = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=goal[i])
            {
                count++;
            }

            if(count>2)
            {
                return false;
            }
        }

        vector<int>v1(26, 0);
        vector<int>v2(26, 0);

        for(int i=0; i<s.length(); i++)
        {
            int ind = s[i] - 'a';
            v1[ind]++;
        }

        for(int i=0; i<goal.length(); i++)
        {
            int ind = goal[i] - 'a';
            v2[ind]++;
        }

        bool flg = false;
        for(int i=0; i<26; i++)
        {
            if(v1[i] != v2[i])
            {
                return false;
            }

            if(v1[i]>=2)
            {
                flg = true;
            }
        }

        if(flag)
        {
            if(!flg)
            {
                return false;
            }
        }
        return true;
    }
};