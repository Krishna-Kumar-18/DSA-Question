class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) 
    {
        if(arr.size()==1)
        {
            return arr[0];
        }
        
        string s = arr[0];
        
        int mini = INT_MAX;
        
        for(int i=1; i<arr.size(); i++)
        {
            string temp = arr[i];
            int count = 0;
            for(int j=0; j<s.length(); j++)
            {
                if(j==temp.length())
                {
                    break;
                }
                
                if(s[j]==temp[j])
                {
                    count++;
                }
                else 
                {
                    break;
                }
            }
            
            if(count==0)
            {
                return "-1";
            }
            
            mini = min(count, mini);
        }
        
        string ans = "";
        for(int i=0; i<mini; i++)
        {
            ans += s[i];
        }
        return ans;
    }
};