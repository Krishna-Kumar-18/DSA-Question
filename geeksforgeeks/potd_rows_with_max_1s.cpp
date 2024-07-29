class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) 
    {
        int maxi = INT_MIN;
        int ans = 0;
        bool flag = false;
        for(int i=0; i<arr.size(); i++)
        {
            int count = 0;
            for(int j=0; j<arr[0].size(); j++)
            {
                if(arr[i][j]==1)
                {
                    count++;
                    flag = true;
                }
            }
            
            if(count > maxi)
            {
                ans = i;
            }
            
            maxi = max(maxi, count);
        }
        
        if(flag)
        {
            return ans;
        }
        return -1;
    }
};