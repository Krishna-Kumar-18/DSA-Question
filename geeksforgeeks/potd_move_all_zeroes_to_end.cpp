class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) 
    {
        vector<int>temp;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]!=0)
            {
                temp.push_back(arr[i]);
            }
        }
        
        for(int i=0; i<temp.size(); i++)
        {
            arr[i] = temp[i];
        }
        
        int size = temp.size();
        
        for(int i=temp.size(); i<arr.size(); i++)
        {
            arr[i] = 0;
        }
    }
};