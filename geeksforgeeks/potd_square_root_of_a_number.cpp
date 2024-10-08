class Solution {
  public:
    long long int floorSqrt(long long int n) 
    {
        long long int ans = -1;
        
        int low = 0;
        int high = n;
        
        while(low<=high)
        {
            long long int mid = low + (high-low)/2;
            
            if(mid*mid == n)
            {
                return mid;
            }
            
            if(mid*mid < n)
            {
                low = mid+1;
                ans = mid;
            }
            else 
            {
                high = mid-1;
            }
        }
        return ans;
    }
};