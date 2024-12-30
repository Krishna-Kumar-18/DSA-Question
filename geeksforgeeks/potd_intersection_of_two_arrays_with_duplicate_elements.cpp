class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) 
    {
        map<int, int>mp_a;
        map<int, int>mp_b;
        
        vector<int>ans;
        
        for(auto i : a)
        {
            mp_a[i]++;
        }
        
        for(auto i : b)
        {
            mp_b[i]++;
        }
        
        for(auto i : mp_a)
        {
            if(mp_b[i.first] >= 1)
            {
                ans.push_back(i.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};