class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) 
    {
        vector<int>temp;
        
        int n = arr.size();
        
        if(d>n)
        {
            d = d%n;
        }
        
        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(i<d)
            {
                temp.push_back(arr[i]);
            }
            else 
            {
                arr[j] = arr[i];
                j++;
            }
        }
        
        for(int i=0; i<temp.size(); i++)
        {
            arr[j] = temp[i];
            j++;
        }
    }
};