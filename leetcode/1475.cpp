class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        vector<int>ans;

        int n = prices.size();

        for(int i=0; i<n; i++)
        {
            int item = prices[i];
            int discount = 0;
            for(int j=i+1; j<n; j++)
            {
                if(item>=prices[j])
                {
                    discount = prices[j];
                    break;
                }
            }
            ans.push_back(item-discount);
        }
        return ans;
    }
};