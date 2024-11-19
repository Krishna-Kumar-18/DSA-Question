class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) 
    {
        unordered_map<int, int>mp;
        vector<int>ans;
        
        for(auto i : arr)
        {
            mp[i]++;
        }
        
        int n = arr.size()/3;
        
        for(auto i : mp)
        {
            if(i.second>n)
            {
                ans.push_back(i.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};