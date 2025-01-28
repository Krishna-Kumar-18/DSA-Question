class Solution {
  public:
    void solve(string &s, set<string>&st, string temp, int ind)
    {
        if(temp.length() == s.length())
        {
            st.insert(temp);
            return;
        }
        
        for(int i=ind; i<s.length(); i++)
        {
            swap(s[i], s[ind]);
            temp.push_back(s[ind]);
            solve(s, st, temp, ind+1);
            temp.pop_back();
            swap(s[i], s[ind]);
        }
    }
    
    vector<string> findPermutation(string &s) 
    {
        vector<string>ans;
        set<string>st;
        
        string temp = "";
        
        solve(s, st, temp, 0);
        
        for(auto i : st)
        {
            ans.push_back(i);
        }
        
        return ans;
    }
};
