class Solution {
public:
    bool isCircularSentence(string s) 
    {
        int n = s.length();

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]-'0'==-16)
            {
                if(s[i-1]!=s[i+1])
                {
                    return false;
                }
            }
        }

        if(s[0]!=s[n-1])
        {
            return false;
        }
        
        return true;
    }
};