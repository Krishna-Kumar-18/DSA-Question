class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) 
    {
        set<vector<int>>s;
        unordered_map<int, vector<pair<int, int>>>mp;
        
        int n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                mp[arr[i]+arr[j]].push_back({i, j});
            }
        }
        
        for(int i=0; i<n; i++)
        {
            int ele = -arr[i];
            if(mp.find(ele)!=mp.end())
            {
                vector<pair<int, int>>pairs = mp[ele];
                for(auto p : pairs)
                {
                    if(i!=p.first && i!=p.second)
                    {
                        vector<int>temp = {i, p.first, p.second};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        
        vector<vector<int>>ans(s.begin(), s.end());
        
        return ans;
    }
};