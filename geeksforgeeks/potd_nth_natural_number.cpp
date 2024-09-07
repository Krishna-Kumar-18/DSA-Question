class Solution {
  public:
    long long findNth(long long n) 
    {
        long long int ans = 0;
        long long int pos = 1;
        
        while(n>0)
        {
            ans += pos*(n%9);
            
            n /= 9;
            
            pos *= 10;
        }
        return ans;
    }
};