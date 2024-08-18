class Solution {
  public:
    bool canSplit(vector<int>& arr) 
    {
        if(arr.size()==1)
        {
            return false;
        }
        
        if(arr.size()==2)
        {
            if(arr[0]==arr[1])
            {
                return true;
            }
            return false;
        }
        
        int low = 0;
        int high = arr.size()-1;
        
        int forward_sum = arr[low];
        int backward_sum = arr[high];
        
        int n = arr.size()-2;
        
        while(n--)
        {
            if(forward_sum >= backward_sum)
            {
                high--;
                backward_sum += arr[high];
            }
            else
            {
                low++;
                forward_sum += arr[low];
            }
        }
        
        if(forward_sum == backward_sum)
        {
            return true;
        }
        return false;
    }
};
