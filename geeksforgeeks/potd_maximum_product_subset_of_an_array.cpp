class Solution {
  public:
    long long int mod = 1e9+7;
    long long int findMaxProduct(vector<int>& arr) 
    {
        int count_0=0, count_pos=0, count_neg=0;
        
        int maxi = INT_MIN;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]<0)
            {
                maxi = max(maxi, arr[i]);
            }
        }
        
        long long int ans = 1;
        
        if(arr.size() == 1)
        {
            return arr[0];
        }
        
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]==0)
            {
                count_0++;
                continue;
            }
            else 
            {
                ans = ans * arr[i];
                ans = ans%mod;
            }
            
            if(arr[i]>0)
            {
                count_pos++;
            }
            
            if(arr[i]<0)
            {
                count_neg++;
            }
        }
        
        if(count_neg==0 && count_pos==0)
        {
            return 0;
        }
        
        if(ans>0)
        {
            return ans;
        }
        
        
        if(count_neg==1 && count_pos==0)
        {
            if(count_0 == 0)
            {
                return ans;
            }
            else 
            {
                return 0;
            }
        }
        
        long long int mini = maxi;
        ans = ans/mini;
        ans = ans%mod;
        
        return ans;
    }
};