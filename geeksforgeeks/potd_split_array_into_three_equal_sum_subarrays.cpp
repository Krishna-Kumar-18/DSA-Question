class Solution {
  public:
    vector<int> findSplit(vector<int>& arr) 
    {
        int sum = 0;
        for(int i : arr)
        {
            sum += i;
        }
        
        if(sum%3!=0)                                               // if sum divided by 3 then it --may be-- possible to split array into three equal sum subarrays
        {
            return {-1, -1};
        }
        
        int required_sum = sum/3;
        int first = -1, second = -1;
        
        sum = 0;
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i];
            if(sum==required_sum)
            {
                if(first==-1)
                {
                    first = i;
                    sum = 0;
                }
                else if(second==-1)
                {
                    second = i;
                    return {first, second};
                }
            }
        }
        
        return {-1, -1};
    }
};