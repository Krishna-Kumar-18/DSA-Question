class Solution {
public:
    bool checkOnesSegment(string s) 
    {
        int count = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(i>0)
            {
                if(s[i]!=s[i-1])
                {
                    count++;
                }
            }
        }

        if(count < 2)
        {
            return true;
        }

        return false;
    }
};