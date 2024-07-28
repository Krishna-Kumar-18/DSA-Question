class Solution {
  public:

    string removeDups(string str) 
    {
        vector<int>v(26, 0);
        
        string ans = "";
        
        for(int i=0; i<str.length(); i++)
        {
            v[str[i]-'a']++;
        }
        
        for(int i=0; i<str.length(); i++)
        {
            int ind = str[i]-'a';
            if(v[ind]>1)
            {
                ans += str[i];
                v[ind] = 0;
            }
            else if(v[ind]==1)
            {
                ans += str[i];
            }
        }
        return ans;
    }
};