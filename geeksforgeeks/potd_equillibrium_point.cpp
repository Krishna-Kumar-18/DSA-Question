class Solution {
  public:
    int findEquilibrium(vector<int> &arr) 
    {
        int n = arr.size();
        
        vector<int>left_sum(n, 0);
        vector<int>right_sum(n, 0);
        
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            left_sum[i] = sum;
        }
        
        sum = 0;
        for(int i=n-1; i>=0; i--)
        {
            sum += arr[i];
            right_sum[i] = sum;
        }
        
        for(int i=0; i<n; i++)
        {
            if(left_sum[i] == right_sum[i])
            {
                return i;
            }
        }
        
        return -1;
    }
};