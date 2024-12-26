class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) 
    {
        
        if(arr.size() == 1)
        {
            return false;
        }
        
        sort(arr.begin(), arr.end());
        
        int i=0; 
        int j=arr.size()-1;
        
        while(i<j)
        {
            if(arr[i]+arr[j] == target)
            {
                return true;
            }
            else if(arr[i]+arr[j] < target)
            {
                i++;
            }
            else 
            {
                j--;
            }
        }
        return false;
    }
};