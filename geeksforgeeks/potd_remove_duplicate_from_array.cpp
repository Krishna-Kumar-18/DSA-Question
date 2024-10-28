class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) 
    {
        set<int>s;
        vector<int>ans;
        
        int curr_size = s.size();
        for(auto i : arr)
        {
            s.insert(i);
            if(curr_size<s.size())
            {
                ans.push_back(i);
                curr_size = s.size();
            }
        }
        
        return ans;
    }
};