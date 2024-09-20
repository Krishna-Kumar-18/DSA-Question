class Solution {
  public:
    int countBuildings(vector<int> &height) 
    {
        int maxi = INT_MIN;
        int ans = 0;
        for(int i=0; i<height.size(); i++)
        {
            if(height[i]>maxi)
            {
                ans++;
            }
            maxi = max(height[i], maxi);
        }
        return ans;
    }
};