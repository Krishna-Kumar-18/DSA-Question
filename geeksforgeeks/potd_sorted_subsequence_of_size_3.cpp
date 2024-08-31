class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) 
    {
        vector<int>ans;
        
        int n = arr.size();
        
        vector<int>left_min(n);
        vector<int>right_max(n);
        
        left_min[0] = arr[0];
        for(int i=1; i<n; i++)
        {
            left_min[i] = min(left_min[i-1], arr[i]);
        }
        
        right_max[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--)
        {
            right_max[i] = max(right_max[i+1], arr[i]);
        }
        
        for(int i=1; i<n-1; i++)
        {
            if(left_min[i-1]<arr[i] && arr[i]<right_max[i+1])
            {
                ans.push_back(left_min[i]);
                ans.push_back(arr[i]);
                ans.push_back(right_max[i]);
                break;
            }
        }
        
        return ans;
    }
};