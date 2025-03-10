class Solution {
  public:
    int maximumProfit(vector<int> &prices) 
    {
        int mini = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); i++)
        {
            ans = max(ans, prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        
        return ans;
    }
};