class Solution {
  public:
    string roundToNearest(string str) 
    {
        string ans = "";
        int n = str.length();
        
        int digit = str[n-1]-'0';
        
        if(digit<=5)
        {
            str[n-1] = '0';
            return str;
        }
        
        bool flag = true;
        for(int i=n-1; i>=0; i--)
        {
            digit = str[i]-'0';
            if(i==n-1 && digit>5)
            {
                ans = '0' + ans;
            }
            else if(digit==9 && flag==true)
            {
                ans = '0' + ans;
            }
            else 
            {
                if(flag)
                {
                    digit += 1;
                    ans = (to_string(digit)) + ans;
                    flag = false;
                }
                else 
                {
                    ans = to_string(digit) + ans;
                }
            }
        }
        
        if(flag)
        {
            ans = '1' + ans;
        }
        
        return ans;
    }
};