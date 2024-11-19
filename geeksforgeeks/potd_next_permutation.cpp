class Solution {
  public:
    void nextPermutation(vector<int>& arr) 
    {
        int n = arr.size(); 
        
        int ind = -1;
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i]<arr[i+1])
            {
                ind = i;
                break;
            }
        }
        
        if(ind==-1)
        {
            reverse(arr.begin(), arr.end());
            return;
        }
        
        int ans = INT_MAX;
        int next_greater_ind = -1;
        for(int i=ind+1; i<n; i++)
        {
            if(arr[i]>arr[ind])
            {
                ans = min(arr[i], ans);
                if(ans == arr[i])
                {
                    next_greater_ind = i;
                }
            }
        }
        
        swap(arr[ind], arr[next_greater_ind]);
        
        reverse(arr.begin()+ind+1, arr.end());
    }
};