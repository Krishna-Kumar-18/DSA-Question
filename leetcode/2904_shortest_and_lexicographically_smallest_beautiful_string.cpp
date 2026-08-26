class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        string ans = "";

        int count = 0;

        int i = 0;
        int j = 0;
        while(j < s.length())
        {
            if(s[j]=='1')
            {
                count++;
            }

            while(count>k)
            {
                if(s[i]=='1')
                {
                    count--;
                }
                i++;
            }

            if(count == k)
            {
                while(s[i]=='0')
                {
                    i++;
                }

                string curr = s.substr(i, j-i+1);

                if(ans=="" || curr.size()<ans.size() || (curr.size()==ans.size() && curr<ans))
                {
                    ans = curr;
                }
            }

            j++;
        }

        return ans;
    }
};