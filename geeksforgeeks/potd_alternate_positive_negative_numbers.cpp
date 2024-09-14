 class Solution {
  public:
    void rearrange(vector<int> &arr) 
    {
        vector<int>pos;
        vector<int>neg;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]>=0)
            {
                pos.push_back(arr[i]);
            }
            else 
            {
                neg.push_back(arr[i]);
            }
        }
        
        int j=0, k=0;
        for(int i=0; i<arr.size(); i++)
        {
            if(j==pos.size())
            {
                arr[i] = neg[k];
                k++;
            }
            else if(k==neg.size())
            {
                arr[i] = pos[j];
                j++;
            }
            else if(i%2==0)
            {
                arr[i] = pos[j];
                j++;
            }
            else
            {
                arr[i] = neg[k];
                k++;
            }
        }
    }
};