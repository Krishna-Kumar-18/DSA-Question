class Solution {
  public:
    int getSecondLargest(vector<int> &arr) 
    {
        sort(arr.begin(), arr.end(), greater<int>());
        
        set<int>s;
        
        for(int i=0; i<arr.size(); i++)
        {
            s.insert(arr[i]);
            if(s.size()==2)
            {
                return arr[i];
            }
        }
        
        return -1;
    }
};