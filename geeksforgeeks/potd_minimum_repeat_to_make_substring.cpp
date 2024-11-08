class Solution {
  public:
    int minRepeats(string& s1, string& s2) 
    {
        if(s1.find(s2)!=-1)
        {
            return 1;
        }
        
        int ans = 1;
        string temp = s1;
        while(s1.size()<s2.size())
        {
            s1 += temp;
            ans++;
        }
        
        if(s1.find(s2)!=-1)
        {
            return ans;
        }
        
        s1 += temp;
        ans++;
        
        if(s1.find(s2)!=-1)
        {
            return ans;
        }
        
        return -1;
    }
};