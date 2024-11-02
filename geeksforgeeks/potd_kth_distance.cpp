class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) 
    {
        map<int, int>mp;
        
        bool flag = false;
        for(int i=0; i<arr.size(); i++)
        {
            if(mp[arr[i]]>0)
            {
                return true;
            }
            else
            {
                mp[arr[i]]++;
                if(flag)
                {
                    mp[arr[i-k]] = 0;
                }
            }
            
            if(i==k)
            {
                mp[arr[i-k]] = 0;
                flag = true;
            }
        }
        
        return false;
    }
};