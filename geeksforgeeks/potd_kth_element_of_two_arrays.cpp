class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) 
    {
        int i=0;
        int j=0;
        
        int ans = -1;
        while(k--)
        {
            if(i==a.size())
            {
                ans = b[j];
                j++;
            }
            else if(j == b.size())
            {
                ans = a[i];
                i++;
            }
            else if(a[i]<=b[j])
            {
                ans = a[i];
                i++;
            }
            else
            {
                ans = b[j];
                j++;
            }
        }
        return ans;
    }
};