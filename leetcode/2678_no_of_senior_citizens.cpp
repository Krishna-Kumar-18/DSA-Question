class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int ans = 0;
        for(int i=0; i<details.size(); i++)
        {
            string s = details[i];
 
            if(s[11]=='7' || s[11]=='8' || s[11]=='9')
            {
                ans++;
            }
            else if(s[11]=='6' && s[12]!='0')
            {
                ans++;
            }
        }
        return ans;
    }
};