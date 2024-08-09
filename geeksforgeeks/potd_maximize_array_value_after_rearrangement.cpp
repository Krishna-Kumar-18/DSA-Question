class Solution {
  public:
    int Maximize(vector<int> &arr) 
    {
        sort(arr.begin(), arr.end());
        
        long long int ans = 0;
        int mod = 1e9+7;
        for(long long int i=0; i<arr.size(); i++)
        {
            ans += (arr[i] * i);
            ans = ans%mod;
        }
        return ans;
    }
};
  