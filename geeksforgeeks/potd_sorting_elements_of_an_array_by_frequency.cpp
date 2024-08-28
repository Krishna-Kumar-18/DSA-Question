class Solution {
  public:
    static bool comp(pair<int, int>&a, pair<int, int>&b)
    {
        if(a.second==b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    
    vector<int> sortByFreq(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        
        vector<int>ans;
        
        map<int, int>mp;
        
        vector<pair<int, int>>v;
        
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto i : mp)
        {
            v.push_back(i);
        }
        
        sort(v.begin(), v.end(), comp);
        
        for(auto i : v)
        {
            int ele = i.first;
            int freq = i.second;
            
            for(int j=0; j<freq; j++)
            {
                ans.push_back(ele);
            }
        }
        return ans;
    }
};