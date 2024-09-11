class Solution {
  public:
    long long minCost(vector<long long>& arr) 
    {
        long long ans = 0;
        
        multiset<long long>ms;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++)
        {
            ms.insert(arr[i]);
        }
        
        while(ms.size()>1)
        {
            auto it = ms.begin();
            long long cost = *it;
            ms.erase(it);
            it = ms.begin();
            cost += *it;
            ms.erase(it);
            ms.insert(cost);
            ans += cost;
        }
        return ans;
    }
};