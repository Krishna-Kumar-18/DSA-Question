class Solution {
  public:
    int countPairs(vector<int> &arr, int target) 
    {
        int n = arr.size();
        
        map<int, int>mp;
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            int ele = arr[i];
            
            if(ele < 0)
            {
                int targ = target + abs(ele);
                
                if(mp[targ]>0)
                {
                    mp[ele]--;
                    ans += mp[targ];
                }
            }
            else 
            {
                int targ = target - ele;
                
                if(mp[targ]>0)
                {
                    mp[ele]--;
                    ans += mp[targ];
                }
            }
        }
        
        return ans;
    }
};