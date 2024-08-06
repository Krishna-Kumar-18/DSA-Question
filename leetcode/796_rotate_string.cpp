class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.length() != goal.length())
        {
            return false;
        }

        for(int i=0; i<s.length(); i++)
        {
            int n = s.length();
            if(s[i]==goal[0])
            {
                int j=0;
                int k=i;
                while(n--)
                {
                    if(s[k]!=goal[j])
                    {
                        break;
                    }
                    j++;
                    k++;
                    if(k==s.length())
                    {
                        k=0;
                    }

                    if(j==s.length())
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};