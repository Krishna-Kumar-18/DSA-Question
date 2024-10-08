class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) 
    {
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i];
            maxi = max(sum, maxi);
            
            if(sum<0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};