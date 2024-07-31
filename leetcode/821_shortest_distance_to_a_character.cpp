class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int>ans;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==c)
            {
                ans.push_back(0);
                continue;
            }

            int count_left = 0;
            int count_right = 0;
            bool flag_left = false;
            bool flag_right = false;
            for(int j=i-1; j>=0; j--)
            {
                if(s[j]==c)
                {
                    count_left++;
                    flag_left = true;
                    break;
                }
                else
                {
                    count_left++;
                }
            }

            for(int j=i+1; j<s.length(); j++)
            {
                if(s[j]==c)
                {
                    count_right++;
                    flag_right = true;
                    break;
                }
                else 
                {
                    count_right++;
                }
            }

            if(flag_left && flag_right)
            {
                ans.push_back(min(count_left, count_right));
            }
            else if(flag_left)
            {
                ans.push_back(count_left);
            }
            else
            {
                ans.push_back(count_right);
            }
        }
        return ans;
    }
};