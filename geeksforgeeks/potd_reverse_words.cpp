class Solution {
  public:
    string reverseWords(string str) 
    {
        string ans = "";
        string temp = "";
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]=='.')
            {
                ans = "." + temp + ans;
                temp = "";
            }
            else 
            {
                temp += str[i];
            }
        }
        ans = temp + ans;
        return ans;
    }
};